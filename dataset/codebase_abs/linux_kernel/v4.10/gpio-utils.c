int F_1 ( const char * V_1 , unsigned int * V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 ,
const char * V_7 )
{
struct V_8 V_9 ;
char * V_10 ;
int V_11 ;
int V_12 ;
int V_13 ;
V_13 = F_2 ( & V_10 , L_1 , V_1 ) ;
if ( V_13 < 0 )
return - V_14 ;
V_11 = F_3 ( V_10 , 0 ) ;
if ( V_11 == - 1 ) {
V_13 = - V_15 ;
fprintf ( V_16 , L_2 , V_10 ) ;
goto V_17;
}
for ( V_12 = 0 ; V_12 < V_3 ; V_12 ++ )
V_9 . V_18 [ V_12 ] = V_2 [ V_12 ] ;
V_9 . V_19 = V_4 ;
strcpy ( V_9 . V_7 , V_7 ) ;
V_9 . V_2 = V_3 ;
if ( V_4 & V_20 )
memcpy ( V_9 . V_21 , V_6 , sizeof( V_9 . V_21 ) ) ;
V_13 = F_4 ( V_11 , V_22 , & V_9 ) ;
if ( V_13 == - 1 ) {
V_13 = - V_15 ;
fprintf ( V_16 , L_3 ,
V_13 ) ;
}
V_17:
if ( F_5 ( V_11 ) == - 1 )
perror ( L_4 ) ;
free ( V_10 ) ;
return V_13 < 0 ? V_13 : V_9 . V_11 ;
}
int F_6 ( const int V_11 , struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_4 ( V_11 , V_23 , V_6 ) ;
if ( V_13 == - 1 ) {
V_13 = - V_15 ;
fprintf ( V_16 , L_5 ,
L_6 , V_13 ) ;
}
return V_13 ;
}
int F_7 ( const int V_11 , struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_4 ( V_11 , V_24 , V_6 ) ;
if ( V_13 == - 1 ) {
V_13 = - V_15 ;
fprintf ( V_16 , L_5 ,
L_7 , V_13 ) ;
}
return V_13 ;
}
int F_8 ( const int V_11 )
{
int V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 == - 1 ) {
perror ( L_8 ) ;
V_13 = - V_15 ;
}
return V_13 ;
}
int F_9 ( const char * V_1 , unsigned int line )
{
struct V_5 V_6 ;
unsigned int V_2 [] = { line } ;
F_10 ( V_1 , V_2 , 1 , & V_6 ) ;
return V_6 . V_25 [ 0 ] ;
}
int F_10 ( const char * V_1 , unsigned int * V_2 ,
unsigned int V_3 , struct V_5 * V_6 )
{
int V_11 ;
int V_13 ;
int V_26 ;
V_13 = F_1 ( V_1 , V_2 , V_3 ,
V_27 , V_6 ,
V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = V_13 ;
V_13 = F_7 ( V_11 , V_6 ) ;
V_26 = F_8 ( V_11 ) ;
return V_13 < 0 ? V_13 : V_26 ;
}
int F_11 ( const char * V_1 , unsigned int line ,
unsigned int V_29 )
{
struct V_5 V_6 ;
unsigned int V_2 [] = { line } ;
V_6 . V_25 [ 0 ] = V_29 ;
return F_12 ( V_1 , V_2 , 1 , & V_6 ) ;
}
int F_12 ( const char * V_1 , unsigned int * V_2 ,
unsigned int V_3 , struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_1 ( V_1 , V_2 , V_3 ,
V_20 , V_6 ,
V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( V_13 ) ;
}
