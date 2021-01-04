/* raw.c */
void parse_mac(void *, char *);
int create_rawsocket(int);
int bind_rawsocket(char *, int, int);
int send_rawpacket(int, unsigned char *, int);
int recv_rawpacket(int, unsigned char *, int);
unsigned char *create_eth(char *, char *, unsigned short);
void print_ethhdr(unsigned char *);
int type_ethhdr(unsigned char *);
void hex_dump(unsigned char *, int);
unsigned char *create_iphdr(unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);
void print_iphdr(unsigned char *);
unsigned char *create_udphdr(unsigned short, unsigned short, unsigned short, unsigned short);
void print_udphdr(unsigned char *);
unsigned char *create_tcphdr(unsigned short, unsigned short, unsigned int, unsigned int, unsigned char, unsigned char, unsigned short, unsigned short, unsigned short);
void print_tcphdr(unsigned char *);
