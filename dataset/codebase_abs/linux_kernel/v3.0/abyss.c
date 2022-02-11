static unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static unsigned short F_3 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int T_1 F_9 ( struct V_6 * V_7 , const struct V_8 * V_9 )
{
static int V_10 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_13 , V_14 ;
unsigned long V_15 ;
if ( V_10 ++ == 0 )
F_10 ( L_1 , V_16 ) ;
if ( F_11 ( V_7 ) )
return - V_17 ;
V_14 = V_7 -> V_18 ;
V_15 = F_12 ( V_7 , 0 ) ;
V_2 = F_13 ( sizeof( struct V_11 ) ) ;
if ( ! V_2 )
return - V_19 ;
if ( ! F_14 ( V_15 , V_20 , V_2 -> V_21 ) ) {
V_13 = - V_22 ;
goto V_23;
}
V_13 = F_15 ( V_7 -> V_18 , V_24 , V_25 ,
V_2 -> V_21 , V_2 ) ;
if ( V_13 )
goto V_26;
V_2 -> V_4 = V_15 ;
V_2 -> V_18 = V_14 ;
F_10 ( L_2 , V_2 -> V_21 ) ;
F_10 ( L_3 ,
V_2 -> V_21 , V_15 , V_2 -> V_18 ) ;
V_2 -> V_4 += 0x10 ;
V_13 = F_16 ( V_2 , & V_7 -> V_2 ) ;
if ( V_13 ) {
F_10 ( L_4 ,
V_2 -> V_21 ) ;
goto V_27;
}
F_17 ( V_2 ) ;
F_10 ( L_5 , V_2 -> V_21 , V_2 -> V_28 ) ;
V_12 = F_18 ( V_2 ) ;
V_12 -> V_29 = V_30 ;
V_12 -> V_31 = F_1 ;
V_12 -> V_32 = F_3 ;
V_12 -> V_33 = F_5 ;
V_12 -> V_34 = F_7 ;
memcpy ( V_12 -> V_35 , L_6 , V_36 + 1 ) ;
V_2 -> V_37 = & V_38 ;
F_19 ( V_7 , V_2 ) ;
F_20 ( V_2 , & V_7 -> V_2 ) ;
V_13 = F_21 ( V_2 ) ;
if ( V_13 )
goto V_39;
return 0 ;
V_39:
F_19 ( V_7 , NULL ) ;
F_22 ( V_2 ) ;
V_27:
F_23 ( V_7 -> V_18 , V_2 ) ;
V_26:
F_24 ( V_15 , V_20 ) ;
V_23:
F_25 ( V_2 ) ;
return V_13 ;
}
static unsigned short V_30 ( struct V_1 * V_2 )
{
unsigned short V_5 = 0 ;
struct V_11 * V_12 = F_18 ( V_2 ) ;
if( V_12 -> V_40 == V_41 )
V_5 |= 0x01 ;
else
V_5 |= 0x00 ;
return V_5 ;
}
static void F_26 ( unsigned long V_42 , unsigned char V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
F_27 ( V_42 , 0 , ( V_43 >> ( 7 - V_44 ) ) & 0x01 ) ;
F_27 ( V_42 , 1 , ( V_43 >> ( 7 - V_44 ) ) & 0x01 ) ;
F_27 ( V_42 , 0 , ( V_43 >> ( 7 - V_44 ) ) & 0x01 ) ;
}
}
static int F_28 ( unsigned long V_42 , unsigned char V_45 , unsigned char V_46 )
{
if ( F_29 ( V_42 , V_45 ) ) {
F_26 ( V_42 , V_46 ) ;
return F_30 ( V_42 ) ;
}
return 0 ;
}
static int F_29 ( unsigned long V_42 , unsigned char V_45 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 10 ; V_44 ++ ) {
F_31 ( V_42 ) ;
F_26 ( V_42 , V_45 ) ;
if ( F_30 ( V_42 ) )
return 1 ;
}
return 0 ;
}
static unsigned char F_32 ( unsigned long V_42 )
{
unsigned char V_5 ;
F_27 ( V_42 , 0 , 1 ) ;
F_27 ( V_42 , 1 , 1 ) ;
V_5 = ( F_2 ( V_42 ) & V_47 ) ? 1 : 0 ;
F_27 ( V_42 , 1 , 1 ) ;
F_27 ( V_42 , 0 , 1 ) ;
return V_5 ;
}
static unsigned char F_33 ( unsigned long V_42 )
{
unsigned char V_48 = 0 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
V_48 <<= 1 ;
V_48 |= F_32 ( V_42 ) ;
}
return V_48 ;
}
static int F_30 ( unsigned long V_42 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 10 ; V_44 ++ ) {
if ( ( F_32 ( V_42 ) & 0x01 ) == 0x00 )
return 1 ;
}
return 0 ;
}
static int F_34 ( unsigned long V_42 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 10 ; V_44 ++ ) {
if ( ( F_32 ( V_42 ) & 0x01 ) == 0x01 )
return 1 ;
}
return 0 ;
}
static void F_27 ( unsigned long V_42 , unsigned char clock , unsigned char V_48 )
{
unsigned char V_5 = V_49 ;
if ( clock )
V_5 |= V_50 ;
if ( V_48 )
V_5 |= V_47 ;
F_6 ( V_5 , V_42 ) ;
F_35 ( 20 ) ;
}
static void F_31 ( unsigned long V_42 )
{
F_27 ( V_42 , 0 , 1 ) ;
F_27 ( V_42 , 1 , 1 ) ;
F_27 ( V_42 , 1 , 0 ) ;
F_27 ( V_42 , 0 , 1 ) ;
}
static unsigned char F_36 ( unsigned long V_42 , unsigned char V_46 )
{
unsigned char V_48 = 0xff ;
if ( F_28 ( V_42 , V_51 , V_46 ) ) {
if ( F_29 ( V_42 , V_52 ) ) {
V_48 = F_33 ( V_42 ) ;
if ( ! F_34 ( V_42 ) )
V_48 = 0xff ;
}
}
return V_48 ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned char V_53 ;
unsigned long V_54 ;
V_54 = V_2 -> V_4 ;
V_53 = F_2 ( V_54 + V_55 ) ;
V_53 |= V_56 ;
F_6 ( V_53 , V_54 + V_55 ) ;
F_35 ( 100 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned char V_53 ;
unsigned long V_54 ;
V_54 = V_2 -> V_4 ;
V_53 = F_2 ( V_54 + V_55 ) ;
V_53 |= V_56 ;
F_6 ( V_53 , V_54 + V_55 ) ;
V_53 &= ~ ( V_56 |
V_57 |
V_58 ) ;
F_6 ( V_53 , V_54 + V_55 ) ;
F_35 ( 100 ) ;
V_53 |= V_56 ;
F_6 ( V_53 , V_54 + V_55 ) ;
V_53 |= V_58 ;
F_6 ( V_53 , V_54 + V_55 ) ;
V_53 |= V_57 ;
F_6 ( V_53 , V_54 + V_55 ) ;
F_6 ( V_59 |
V_60 ,
V_54 + V_61 ) ;
F_6 ( 30 , V_54 + V_62 ) ;
return 0 ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
V_54 = V_2 -> V_4 ;
F_6 ( 0 , V_54 + V_55 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
unsigned long V_54 ;
unsigned short V_5 ;
int V_44 ;
V_12 = F_18 ( V_2 ) ;
V_54 = V_2 -> V_4 ;
F_37 ( V_2 ) ;
V_5 = F_36 ( V_54 + V_63 ,
V_64 ) ;
V_12 -> V_40 = V_5 ? V_41 : V_65 ;
F_10 ( L_7 , V_2 -> V_21 , V_12 -> V_40 ) ;
V_5 = F_36 ( V_54 + V_63 ,
V_66 ) * 128 ;
F_10 ( L_8 , V_2 -> V_21 , V_5 ) ;
V_2 -> V_67 = 6 ;
for ( V_44 = 0 ; V_44 < 6 ; V_44 ++ )
V_2 -> V_28 [ V_44 ] = F_36 ( V_54 + V_63 ,
V_68 + V_44 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static void T_2 F_44 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_45 ( V_7 ) ;
F_46 ( ! V_2 ) ;
F_47 ( V_2 ) ;
F_24 ( V_2 -> V_4 - 0x10 , V_20 ) ;
F_23 ( V_2 -> V_18 , V_2 ) ;
F_22 ( V_2 ) ;
F_25 ( V_2 ) ;
F_19 ( V_7 , NULL ) ;
}
static int T_3 F_48 ( void )
{
V_38 = V_69 ;
V_38 . V_70 = F_40 ;
V_38 . V_71 = F_42 ;
return F_49 ( & V_72 ) ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_72 ) ;
}
