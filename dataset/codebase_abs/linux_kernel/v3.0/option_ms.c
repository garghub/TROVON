static int F_1 ( struct V_1 * V_2 )
{
const unsigned char V_3 [] = {
0x55 , 0x53 , 0x42 , 0x43 , 0x78 , 0x56 , 0x34 , 0x12 ,
0x01 , 0x00 , 0x00 , 0x00 , 0x80 , 0x00 , 0x06 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
char * V_4 ;
int V_5 ;
F_2 ( L_1 , L_2 ) ;
V_4 = F_3 ( V_6 , V_7 ) ;
if ( V_4 == NULL )
return V_8 ;
memcpy ( V_4 , V_3 , sizeof( V_3 ) ) ;
V_5 = F_4 ( V_2 ,
V_2 -> V_9 ,
V_4 , sizeof( V_3 ) , NULL ) ;
if ( V_5 != V_10 ) {
V_5 = V_11 ;
goto V_12;
}
F_4 ( V_2 ,
V_2 -> V_13 ,
V_4 , V_6 , NULL ) ;
F_4 ( V_2 ,
V_2 -> V_13 ,
V_4 , 13 , NULL ) ;
V_5 = V_10 ;
V_12:
F_5 ( V_4 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const unsigned char V_14 [] = {
0x55 , 0x53 , 0x42 , 0x43 , 0x12 , 0x34 , 0x56 , 0x78 ,
0x24 , 0x00 , 0x00 , 0x00 , 0x80 , 0x00 , 0x06 , 0x12 ,
0x00 , 0x00 , 0x00 , 0x24 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
char * V_4 ;
int V_5 ;
F_2 ( L_1 , L_3 ) ;
V_4 = F_3 ( 0x24 , V_7 ) ;
if ( V_4 == NULL )
return V_8 ;
memcpy ( V_4 , V_14 , sizeof( V_14 ) ) ;
V_5 = F_4 ( V_2 ,
V_2 -> V_9 ,
V_4 , sizeof( V_14 ) , NULL ) ;
if ( V_5 != V_10 ) {
V_5 = V_11 ;
goto V_12;
}
V_5 = F_4 ( V_2 ,
V_2 -> V_13 ,
V_4 , 0x24 , NULL ) ;
if ( V_5 != V_10 ) {
V_5 = V_11 ;
goto V_12;
}
V_5 = memcmp ( V_4 + 8 , L_4 , 6 ) ;
if ( V_5 != 0 )
V_5 = memcmp ( V_4 + 8 , L_5 , 8 ) ;
F_4 ( V_2 ,
V_2 -> V_13 ,
V_4 , 13 , NULL ) ;
V_12:
F_5 ( V_4 ) ;
return V_5 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
F_2 ( L_6 ) ;
V_5 = F_6 ( V_2 ) ;
if ( V_5 != 0 ) {
F_2 ( L_7
L_8 ) ;
return 0 ;
} else
F_2 ( L_9
L_10 ) ;
if ( V_15 == V_16 ) {
F_2 ( L_1 , L_11 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 != V_10 )
F_2 ( L_12 ) ;
return - V_17 ;
} else if ( V_15 == V_18 ) {
F_2 ( L_1 , L_13
L_14 ) ;
}
return 0 ;
}
