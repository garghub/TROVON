static char * F_1 ( void )
{
static char V_1 [ 40 ] ;
char * V_2 ;
struct V_3 * V_4 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = V_1 ;
V_4 = V_5 . V_6 ;
while ( V_4 -> V_7 != V_8 ) {
if ( V_4 -> V_7 != V_9 && V_4 -> V_7 != V_10 &&
V_4 -> V_7 != V_11 )
V_2 = V_2 + sprintf ( V_2 , V_4 -> V_12 . V_13 . V_14 ,
V_4 -> V_12 . V_13 . V_15 ) ;
V_4 ++ ;
}
V_2 = V_2 + sprintf ( V_2 , L_1 ) ;
return V_1 ;
}
static int F_2 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
unsigned long V_19 ;
F_3 ( & V_20 . V_21 , V_19 ) ;
if ( V_5 . V_22 ) {
F_4 ( & V_20 . V_21 , V_19 ) ;
return - V_23 ;
}
V_5 . V_22 = 1 ;
F_4 ( & V_20 . V_21 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
unsigned long V_19 ;
F_3 ( & V_20 . V_21 , V_19 ) ;
V_5 . V_22 = 0 ;
V_24 = 0 ;
F_4 ( & V_20 . V_21 , V_19 ) ;
F_6 () ;
return 0 ;
}
static T_1 F_7 ( struct V_17 * V_18 , char T_2 * V_1 , T_3 V_25 ,
T_4 * V_26 , int V_27 )
{
int V_28 = 0 ;
char T_2 * V_2 ;
char * V_29 ;
T_5 V_30 ;
int V_31 ;
unsigned long V_19 ;
F_8 ( V_32 ) ;
F_3 ( & V_20 . V_21 , V_19 ) ;
while ( 1 ) {
F_9 ( & V_33 , & V_32 , V_34 ) ;
if ( ! V_27 )
F_10 () ;
if ( ! F_11 () || V_20 . V_35 )
break;
F_4 ( & V_20 . V_21 , V_19 ) ;
if ( V_18 -> V_36 & V_37 ) {
F_12 ( & V_33 , & V_32 ) ;
return - V_38 ;
}
if ( F_13 ( V_39 ) ) {
F_12 ( & V_33 , & V_32 ) ;
return - V_40 ;
}
F_14 () ;
F_3 ( & V_20 . V_21 , V_19 ) ;
}
F_12 ( & V_33 , & V_32 ) ;
V_2 = V_1 ;
V_29 = F_1 () ;
while ( V_28 <= V_25 - 3 ) {
if ( V_20 . V_35 ) {
V_20 . V_35 = 0 ;
V_30 = '\x18' ;
} else if ( V_29 [ V_24 ] ) {
V_30 = V_29 [ V_24 ++ ] ;
} else {
if ( ! V_27 )
F_10 () ;
if ( F_11 () )
break;
V_30 = F_15 () ;
}
F_4 ( & V_20 . V_21 , V_19 ) ;
if ( ( ! V_27 && V_30 < 0x100 ) || ( V_27 && V_30 < 0x80 ) ) {
T_6 V_41 = V_30 ;
if ( F_16 ( V_2 , & V_41 , 1 ) )
return - V_42 ;
V_28 ++ ;
V_2 ++ ;
} else if ( V_27 && V_30 < 0x800 ) {
T_6 V_43 [ 2 ] = {
0xc0 | ( V_30 >> 6 ) ,
0x80 | ( V_30 & 0x3f )
} ;
if ( F_16 ( V_2 , V_43 , sizeof( V_43 ) ) )
return - V_42 ;
V_28 += sizeof( V_43 ) ;
V_2 += sizeof( V_43 ) ;
} else if ( V_27 ) {
T_6 V_43 [ 3 ] = {
0xe0 | ( V_30 >> 12 ) ,
0x80 | ( ( V_30 >> 6 ) & 0x3f ) ,
0x80 | ( V_30 & 0x3f )
} ;
if ( F_16 ( V_2 , V_43 , sizeof( V_43 ) ) )
return - V_42 ;
V_28 += sizeof( V_43 ) ;
V_2 += sizeof( V_43 ) ;
}
F_3 ( & V_20 . V_21 , V_19 ) ;
}
* V_26 += V_28 ;
V_31 = F_11 () ;
F_4 ( & V_20 . V_21 , V_19 ) ;
if ( V_31 ) {
F_6 () ;
* V_26 = 0 ;
}
return V_28 ;
}
static T_1 F_17 ( struct V_17 * V_18 , char T_2 * V_1 , T_3 V_25 ,
T_4 * V_26 )
{
return F_7 ( V_18 , V_1 , V_25 , V_26 , 0 ) ;
}
static T_1 F_18 ( struct V_17 * V_18 , char T_2 * V_1 , T_3 V_25 ,
T_4 * V_26 )
{
return F_7 ( V_18 , V_1 , V_25 , V_26 , 1 ) ;
}
static T_1 F_19 ( struct V_17 * V_18 , const char T_2 * V_1 ,
T_3 V_25 , T_4 * V_26 )
{
unsigned long V_44 = 0 ;
int V_45 ;
V_45 = F_20 ( V_1 , V_25 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
V_46 = V_44 ;
return V_25 ;
}
static unsigned int F_21 ( struct V_17 * V_18 , struct V_47 * V_32 )
{
unsigned long V_19 ;
int V_48 = 0 ;
F_22 ( V_18 , & V_33 , V_32 ) ;
F_3 ( & V_20 . V_21 , V_19 ) ;
if ( ! F_11 () || V_20 . V_35 )
V_48 = V_49 | V_50 ;
F_4 ( & V_20 . V_21 , V_19 ) ;
return V_48 ;
}
static unsigned char F_23 ( struct V_51 * V_52 )
{
int V_53 ;
V_53 = V_46 ;
V_46 = 0 ;
return V_53 ;
}
static int F_24 ( struct V_51 * V_52 )
{
if ( V_54 != 0 )
return 0 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_57 ;
V_55 . V_58 = L_2 ;
V_55 . V_59 = & V_60 ;
if ( F_25 ( & V_55 ) ) {
F_26 ( L_3 ) ;
return - V_61 ;
}
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_56 = V_63 ;
V_62 . V_58 = L_4 ;
V_62 . V_59 = & V_64 ;
if ( F_25 ( & V_62 ) ) {
F_26 ( L_3 ) ;
return - V_61 ;
}
V_54 = 1 ;
F_27 ( L_5 ) ;
F_27 ( L_6 ) ;
return 0 ;
}
static void F_28 ( void )
{
F_29 ( & V_55 ) ;
F_29 ( & V_62 ) ;
V_54 = 0 ;
F_27 ( L_7 ) ;
F_27 ( L_8 ) ;
}
static int F_30 ( struct V_51 * V_52 )
{
if ( V_5 . V_22 )
return 1 ;
return 0 ;
}
