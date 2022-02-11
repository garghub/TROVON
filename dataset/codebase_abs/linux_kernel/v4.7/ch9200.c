static int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned short V_4 ,
unsigned short V_5 , void * V_6 , unsigned short V_7 ,
int V_8 )
{
unsigned char * V_9 = NULL ;
unsigned char V_10 ;
int V_11 = 0 ;
if ( V_3 == V_12 )
V_10 = ( V_13 | V_14 | V_15 ) ;
else
V_10 = ( V_13 | V_14 |
V_16 ) ;
F_2 ( V_2 -> V_17 , L_1 ,
V_5 , V_7 ) ;
V_9 = F_3 ( V_7 , V_18 ) ;
if ( ! V_9 ) {
V_11 = - V_19 ;
goto V_20;
}
V_11 = F_4 ( V_2 -> V_21 ,
F_5 ( V_2 -> V_21 , 0 ) ,
V_3 , V_10 , V_4 , V_5 , V_9 , V_7 ,
V_8 ) ;
if ( V_11 == V_7 )
memcpy ( V_6 , V_9 , V_7 ) ;
else if ( V_11 >= 0 )
V_11 = - V_22 ;
F_6 ( V_9 ) ;
return V_11 ;
V_20:
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned short V_4 , unsigned short V_5 ,
void * V_6 , unsigned short V_7 , int V_8 )
{
unsigned char * V_9 = NULL ;
unsigned char V_10 ;
int V_11 = 0 ;
if ( V_3 == V_23 )
V_10 = ( V_24 | V_14 |
V_15 ) ;
else
V_10 = ( V_24 | V_14 |
V_16 ) ;
F_2 ( V_2 -> V_17 , L_2 ,
V_5 , V_7 ) ;
if ( V_6 ) {
V_9 = F_8 ( V_6 , V_7 , V_18 ) ;
if ( ! V_9 ) {
V_11 = - V_19 ;
goto V_20;
}
}
V_11 = F_4 ( V_2 -> V_21 ,
F_9 ( V_2 -> V_21 , 0 ) ,
V_3 , V_10 , V_4 , V_5 , V_9 , V_7 ,
V_8 ) ;
if ( V_11 >= 0 && V_11 < V_7 )
V_11 = - V_22 ;
F_6 ( V_9 ) ;
return 0 ;
V_20:
return V_11 ;
}
static int F_10 ( struct V_25 * V_26 , int V_27 , int V_28 )
{
struct V_1 * V_2 = F_11 ( V_26 ) ;
unsigned char V_29 [ 2 ] ;
F_2 ( V_26 , L_3 ,
V_27 , V_28 ) ;
if ( V_27 != 0 )
return - V_30 ;
F_1 ( V_2 , V_12 , 0 , V_28 * 2 , V_29 , 0x02 ,
V_31 ) ;
return ( V_29 [ 0 ] | V_29 [ 1 ] << 8 ) ;
}
static void F_12 ( struct V_25 * V_26 ,
int V_27 , int V_28 , int V_32 )
{
struct V_1 * V_2 = F_11 ( V_26 ) ;
unsigned char V_29 [ 2 ] ;
F_2 ( V_26 , L_4 ,
V_27 , V_28 ) ;
if ( V_27 != 0 )
return;
V_29 [ 0 ] = ( unsigned char ) V_32 ;
V_29 [ 1 ] = ( unsigned char ) ( V_32 >> 8 ) ;
F_7 ( V_2 , V_23 , 0 , V_28 * 2 , V_29 , 0x02 ,
V_31 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_33 V_34 ;
F_14 ( & V_2 -> V_35 , 1 , 1 ) ;
F_15 ( & V_2 -> V_35 , & V_34 ) ;
F_2 ( V_2 -> V_17 , L_5 ,
V_34 . V_36 , V_34 . V_37 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
int V_39 ;
unsigned char * V_9 ;
if ( V_38 -> V_40 < 16 )
return;
V_9 = V_38 -> V_41 ;
V_39 = ! ! ( V_9 [ 0 ] & 0x01 ) ;
if ( V_39 ) {
F_17 ( V_2 -> V_17 ) ;
F_18 ( V_2 , V_42 ) ;
} else {
F_19 ( V_2 -> V_17 ) ;
}
}
static struct V_43 * F_20 ( struct V_1 * V_2 , struct V_43 * V_44 ,
T_1 V_45 )
{
int V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
V_48 = 0x40 ;
V_47 = V_44 -> V_47 ;
if ( F_21 ( V_44 ) < V_48 ) {
struct V_43 * V_49 ;
V_49 = F_22 ( V_44 , V_48 , 0 , V_45 ) ;
F_23 ( V_44 ) ;
V_44 = V_49 ;
if ( ! V_44 )
return NULL ;
}
F_24 ( V_44 , V_48 ) ;
if ( ( V_44 -> V_47 % V_2 -> V_50 ) == 0 )
V_47 ++ ;
V_44 -> V_6 [ 0 ] = V_47 ;
V_44 -> V_6 [ 1 ] = V_47 >> 8 ;
V_44 -> V_6 [ 2 ] = 0x00 ;
V_44 -> V_6 [ 3 ] = 0x80 ;
for ( V_46 = 4 ; V_46 < 48 ; V_46 ++ )
V_44 -> V_6 [ V_46 ] = 0x00 ;
V_44 -> V_6 [ 48 ] = V_47 ;
V_44 -> V_6 [ 49 ] = V_47 >> 8 ;
V_44 -> V_6 [ 50 ] = 0x00 ;
V_44 -> V_6 [ 51 ] = 0x80 ;
for ( V_46 = 52 ; V_46 < 64 ; V_46 ++ )
V_44 -> V_6 [ V_46 ] = 0x00 ;
return V_44 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
int V_47 = 0 ;
int V_51 = 0 ;
V_51 = 64 ;
if ( F_26 ( V_44 -> V_47 < V_51 ) ) {
F_27 ( & V_2 -> V_21 -> V_2 , L_6 ) ;
return 0 ;
}
V_47 = ( V_44 -> V_6 [ V_44 -> V_47 - 16 ] | V_44 -> V_6 [ V_44 -> V_47 - 15 ] << 8 ) ;
F_28 ( V_44 , V_47 ) ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned char * V_6 )
{
int V_11 = 0 ;
unsigned char V_52 [ 0x06 ] ;
int V_53 = 0 ;
F_2 ( V_2 -> V_17 , L_7 ,
V_2 -> V_21 -> V_54 . V_55 ,
V_2 -> V_21 -> V_54 . V_56 ) ;
memset ( V_52 , 0 , sizeof( V_52 ) ) ;
V_53 = F_1 ( V_2 , V_12 , 0 ,
V_57 , V_52 , 0x02 ,
V_31 ) ;
V_53 += F_1 ( V_2 , V_12 , 0 , V_58 ,
V_52 + 2 , 0x02 , V_31 ) ;
V_53 += F_1 ( V_2 , V_12 , 0 , V_59 ,
V_52 + 4 , 0x02 , V_31 ) ;
if ( V_53 != V_60 )
V_11 = - V_22 ;
V_6 [ 0 ] = V_52 [ 5 ] ;
V_6 [ 1 ] = V_52 [ 4 ] ;
V_6 [ 2 ] = V_52 [ 3 ] ;
V_6 [ 3 ] = V_52 [ 2 ] ;
V_6 [ 4 ] = V_52 [ 1 ] ;
V_6 [ 5 ] = V_52 [ 0 ] ;
return V_11 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
int V_63 = 0 ;
unsigned char V_6 [ 2 ] ;
V_63 = F_31 ( V_2 , V_62 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_35 . V_2 = V_2 -> V_17 ;
V_2 -> V_35 . V_64 = F_10 ;
V_2 -> V_35 . V_65 = F_12 ;
V_2 -> V_35 . V_66 = 0x1f ;
V_2 -> V_35 . V_67 = 0x1f ;
V_2 -> V_68 = V_2 -> V_17 -> V_69 + V_2 -> V_17 -> V_70 ;
V_2 -> V_71 = 24 * 64 + 16 ;
F_32 ( & V_2 -> V_35 ) ;
V_6 [ 0 ] = 0x01 ;
V_6 [ 1 ] = 0x0F ;
V_63 = F_7 ( V_2 , V_23 , 0 , V_72 , V_6 ,
0x02 , V_31 ) ;
V_6 [ 0 ] = 0xA0 ;
V_6 [ 1 ] = 0x90 ;
V_63 = F_7 ( V_2 , V_23 , 0 , V_73 , V_6 ,
0x02 , V_31 ) ;
V_6 [ 0 ] = 0x30 ;
V_6 [ 1 ] = 0x00 ;
V_63 = F_7 ( V_2 , V_23 , 0 , V_74 , V_6 ,
0x02 , V_31 ) ;
V_6 [ 0 ] = 0x17 ;
V_6 [ 1 ] = 0xD8 ;
V_63 = F_7 ( V_2 , V_23 , 0 , V_75 ,
V_6 , 0x02 , V_31 ) ;
V_6 [ 0 ] = 0x01 ;
V_6 [ 1 ] = 0x00 ;
V_63 = F_7 ( V_2 , V_23 , 0 , 254 , V_6 , 0x02 ,
V_31 ) ;
V_6 [ 0 ] = 0x5F ;
V_6 [ 1 ] = 0x0D ;
V_63 = F_7 ( V_2 , V_23 , 0 , V_76 , V_6 , 0x02 ,
V_31 ) ;
V_63 = F_29 ( V_2 , V_2 -> V_17 -> V_77 ) ;
return V_63 ;
}
