static inline int F_1 ( unsigned char V_1 )
{
return V_1 < ' ' || V_1 == '"' || V_1 == '*' || V_1 == '/' || V_1 == ':' || V_1 == '<' ||
V_1 == '>' || V_1 == '?' || V_1 == '\\' || V_1 == '|' ;
}
static inline int F_2 ( unsigned char V_1 )
{
return V_1 == '+' || V_1 == ',' || V_1 == ';' || V_1 == '=' || V_1 == '[' || V_1 == ']' ;
}
static inline unsigned char F_3 ( unsigned char * V_2 , unsigned char V_3 )
{
if ( V_3 < 128 || V_3 == 255 ) return V_3 >= 'a' && V_3 <= 'z' ? V_3 - 0x20 : V_3 ;
if ( ! V_2 ) return V_3 ;
return V_2 [ V_3 - 128 ] ;
}
unsigned char F_4 ( unsigned char * V_2 , unsigned char V_3 )
{
return F_3 ( V_2 , V_3 ) ;
}
static inline unsigned char F_5 ( unsigned char * V_2 , unsigned char V_3 )
{
if ( V_3 < 128 || V_3 == 255 ) return V_3 >= 'A' && V_3 <= 'Z' ? V_3 + 0x20 : V_3 ;
if ( ! V_2 ) return V_3 ;
return V_2 [ V_3 ] ;
}
int F_6 ( const unsigned char * V_4 , unsigned * V_5 )
{
int V_6 ;
if ( * V_5 > 254 ) return - V_7 ;
F_7 ( V_4 , V_5 ) ;
if ( ! * V_5 ) return - V_8 ;
for ( V_6 = 0 ; V_6 < * V_5 ; V_6 ++ ) if ( F_1 ( V_4 [ V_6 ] ) ) return - V_8 ;
if ( * V_5 == 1 ) if ( V_4 [ 0 ] == '.' ) return - V_8 ;
if ( * V_5 == 2 ) if ( V_4 [ 0 ] == '.' && V_4 [ 1 ] == '.' ) return - V_8 ;
return 0 ;
}
unsigned char * F_8 ( struct V_9 * V_10 , unsigned char * V_11 ,
unsigned V_5 , int V_12 , int V_13 )
{
unsigned char * V_14 ;
int V_6 ;
if ( F_9 ( V_10 ) -> V_15 >= 2 ) if ( F_10 ( V_11 , V_5 ) != V_13 ) {
F_11 ( L_1 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_12 ( L_2 , V_11 [ V_6 ] ) ;
F_12 ( L_3 , V_13 ? L_4 : L_5 ) ;
F_11 ( L_6 ) ;
}
if ( ! V_12 ) return V_11 ;
if ( ! ( V_14 = F_13 ( V_5 , V_16 ) ) ) {
F_11 ( L_7 ) ;
return V_11 ;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) V_14 [ V_6 ] = F_5 ( F_9 ( V_10 ) -> V_17 , V_11 [ V_6 ] ) ;
return V_14 ;
}
int F_14 ( struct V_9 * V_10 ,
const unsigned char * V_18 , unsigned V_19 ,
const unsigned char * V_20 , unsigned V_21 , int V_22 )
{
unsigned V_23 = V_19 < V_21 ? V_19 : V_21 ;
unsigned V_6 ;
if ( V_22 ) return - 1 ;
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
unsigned char V_24 = F_3 ( F_9 ( V_10 ) -> V_17 , V_18 [ V_6 ] ) ;
unsigned char V_25 = F_3 ( F_9 ( V_10 ) -> V_17 , V_20 [ V_6 ] ) ;
if ( V_24 < V_25 ) return - 1 ;
if ( V_24 > V_25 ) return 1 ;
}
if ( V_19 < V_21 ) return - 1 ;
if ( V_19 > V_21 ) return 1 ;
return 0 ;
}
int F_10 ( const unsigned char * V_4 , unsigned V_5 )
{
int V_6 , V_26 ;
for ( V_6 = 0 ; V_6 < V_5 && V_4 [ V_6 ] != '.' ; V_6 ++ )
if ( F_2 ( V_4 [ V_6 ] ) ) return 1 ;
if ( ! V_6 || V_6 > 8 ) return 1 ;
if ( V_6 == V_5 ) return 0 ;
for ( V_26 = V_6 + 1 ; V_26 < V_5 ; V_26 ++ )
if ( V_4 [ V_26 ] == '.' || F_2 ( V_4 [ V_6 ] ) ) return 1 ;
return V_26 - V_6 > 4 ;
}
void F_7 ( const unsigned char * V_4 , unsigned * V_5 )
{
if ( ! * V_5 ) return;
if ( * V_5 == 1 && V_4 [ 0 ] == '.' ) return;
if ( * V_5 == 2 && V_4 [ 0 ] == '.' && V_4 [ 1 ] == '.' ) return;
while ( * V_5 && ( V_4 [ * V_5 - 1 ] == '.' || V_4 [ * V_5 - 1 ] == ' ' ) )
( * V_5 ) -- ;
}
