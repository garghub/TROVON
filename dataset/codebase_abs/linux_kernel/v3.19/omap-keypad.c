static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ )
F_2 ( V_5 [ V_3 ] , V_2 & ( 1 << V_3 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_1 )
{
int V_6 ;
T_1 V_2 = 0 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_7 ; V_6 ++ ) {
if ( F_4 ( V_8 [ V_6 ] ) )
V_2 |= ( 1 << V_6 ) ;
}
return V_2 ;
}
static T_2 F_5 ( int V_9 , void * V_10 )
{
F_6 ( 1 , V_11 + V_12 ) ;
F_7 ( & V_13 ) ;
return V_14 ;
}
static void F_8 ( unsigned long V_15 )
{
F_7 ( & V_13 ) ;
}
static void F_9 ( struct V_1 * V_1 , unsigned char * V_16 )
{
int V_3 = 0 ;
F_6 ( 1 , V_11 + V_12 ) ;
F_6 ( 0xff , V_11 + V_17 ) ;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ ) {
F_6 ( ~ ( 1 << V_3 ) & 0xff ,
V_11 + V_17 ) ;
F_10 ( V_1 -> V_18 ) ;
V_16 [ V_3 ] = ~ F_11 ( V_11 +
V_19 ) & 0xff ;
}
F_6 ( 0x00 , V_11 + V_17 ) ;
F_10 ( 2 ) ;
}
static void F_12 ( unsigned long V_15 )
{
struct V_1 * V_20 = (struct V_1 * ) V_15 ;
unsigned short * V_21 = V_20 -> V_22 -> V_23 ;
unsigned int V_24 = F_13 ( V_20 -> V_4 ) ;
unsigned char V_25 [ 8 ] , V_26 , V_27 = 0 ;
int V_3 , V_6 ;
int V_28 = 0 ;
F_9 ( V_20 , V_25 ) ;
for ( V_3 = 0 ; V_3 < V_20 -> V_4 ; V_3 ++ ) {
V_26 = V_25 [ V_3 ] ^ V_29 [ V_3 ] ;
V_27 |= V_25 [ V_3 ] ;
if ( V_26 == 0 )
continue;
for ( V_6 = 0 ; V_6 < V_20 -> V_7 ; V_6 ++ ) {
int V_30 ;
if ( ! ( V_26 & ( 1 << V_6 ) ) )
continue;
#ifdef F_14
F_15 ( V_31 L_1 , V_3 ,
V_6 , ( V_25 [ V_3 ] & ( 1 << V_6 ) ) ?
L_2 : L_3 ) ;
#else
V_30 = V_21 [ F_16 ( V_6 , V_3 , V_24 ) ] ;
if ( V_30 < 0 ) {
F_15 ( V_32
L_4 ,
V_3 , V_6 ) ;
V_28 = 1 ;
continue;
}
if ( ! ( V_33 == ( V_30 & V_34 ) ||
V_33 == - 1 ) )
continue;
V_33 = V_30 & V_34 ;
F_17 ( V_20 -> V_22 , V_30 & ~ V_34 ,
V_25 [ V_3 ] & ( 1 << V_6 ) ) ;
#endif
}
}
F_18 ( V_20 -> V_22 ) ;
memcpy ( V_29 , V_25 , sizeof( V_29 ) ) ;
if ( V_27 ) {
int V_18 = V_35 / 20 ;
if ( V_28 )
V_18 = 2 * V_35 ;
F_19 ( & V_20 -> V_36 , V_37 + V_18 ) ;
} else {
F_6 ( 0 , V_11 + V_12 ) ;
V_33 = - 1 ;
}
}
static T_3 F_20 ( struct V_38 * V_39 ,
struct V_40 * V_41 , char * V_42 )
{
return sprintf ( V_42 , L_5 , V_43 ) ;
}
static T_3 F_21 ( struct V_38 * V_39 , struct V_40 * V_41 ,
const char * V_42 , T_4 V_44 )
{
struct V_1 * V_1 = F_22 ( V_39 ) ;
int V_16 ;
if ( sscanf ( V_42 , L_6 , & V_16 ) != 1 )
return - V_45 ;
if ( ( V_16 != 1 ) && ( V_16 != 0 ) )
return - V_45 ;
F_23 ( & V_46 ) ;
if ( V_16 != V_43 ) {
if ( V_16 )
F_24 ( V_1 -> V_9 ) ;
else
F_25 ( V_1 -> V_9 ) ;
V_43 = V_16 ;
}
F_26 ( & V_46 ) ;
return F_27 ( V_42 , V_44 ) ;
}
static int F_28 ( struct V_47 * V_39 , T_5 V_16 )
{
return 0 ;
}
static int F_29 ( struct V_47 * V_39 )
{
return 0 ;
}
static int F_30 ( struct V_47 * V_48 )
{
struct V_1 * V_1 ;
struct V_49 * V_49 ;
struct V_50 * V_51 = F_31 ( & V_48 -> V_39 ) ;
int V_52 , V_53 , V_54 , V_55 ;
unsigned int V_24 , V_56 ;
if ( ! V_51 -> V_7 || ! V_51 -> V_4 || ! V_51 -> V_57 ) {
F_15 ( V_58 L_7 ) ;
return - V_45 ;
}
V_24 = F_13 ( V_51 -> V_4 ) ;
V_56 = V_51 -> V_7 << V_24 ;
V_1 = F_32 ( sizeof( struct V_1 ) +
V_56 * sizeof( unsigned short ) , V_59 ) ;
V_49 = F_33 () ;
if ( ! V_1 || ! V_49 ) {
F_34 ( V_1 ) ;
F_35 ( V_49 ) ;
return - V_60 ;
}
F_36 ( V_48 , V_1 ) ;
V_1 -> V_22 = V_49 ;
F_6 ( 1 , V_11 + V_12 ) ;
if ( V_51 -> V_18 )
V_1 -> V_18 = V_51 -> V_18 ;
if ( V_51 -> V_8 && V_51 -> V_5 ) {
V_8 = V_51 -> V_8 ;
V_5 = V_51 -> V_5 ;
}
V_1 -> V_7 = V_51 -> V_7 ;
V_1 -> V_4 = V_51 -> V_4 ;
V_53 = 0 ;
V_54 = 0 ;
F_37 ( & V_1 -> V_36 , F_8 , ( unsigned long ) V_1 ) ;
F_38 ( & V_13 ) ;
V_13 . V_15 = ( unsigned long ) V_1 ;
V_55 = F_39 ( & V_48 -> V_39 , & V_61 ) ;
if ( V_55 < 0 )
goto V_62;
V_49 -> V_63 = L_8 ;
V_49 -> V_64 = L_9 ;
V_49 -> V_39 . V_65 = & V_48 -> V_39 ;
V_49 -> V_66 . V_67 = V_68 ;
V_49 -> V_66 . V_69 = 0x0001 ;
V_49 -> V_66 . V_70 = 0x0001 ;
V_49 -> V_66 . V_71 = 0x0100 ;
if ( V_51 -> V_72 )
F_40 ( V_73 , V_49 -> V_74 ) ;
V_55 = F_41 ( V_51 -> V_57 , NULL ,
V_51 -> V_7 , V_51 -> V_4 ,
V_1 -> V_75 , V_49 ) ;
if ( V_55 < 0 )
goto V_76;
V_55 = F_42 ( V_1 -> V_22 ) ;
if ( V_55 < 0 ) {
F_15 ( V_58 L_10 ) ;
goto V_76;
}
if ( V_51 -> V_77 )
F_6 ( 0xff , V_11 + V_78 ) ;
F_9 ( V_1 , V_29 ) ;
V_1 -> V_9 = F_43 ( V_48 , 0 ) ;
if ( V_1 -> V_9 >= 0 ) {
if ( F_44 ( V_1 -> V_9 , F_5 , 0 ,
L_8 , V_1 ) < 0 )
goto V_79;
}
F_6 ( 0 , V_11 + V_12 ) ;
return 0 ;
V_79:
F_45 ( V_1 -> V_22 ) ;
V_49 = NULL ;
V_76:
F_46 ( & V_48 -> V_39 , & V_61 ) ;
V_62:
for ( V_52 = V_54 - 1 ; V_52 >= 0 ; V_52 -- )
F_47 ( V_8 [ V_52 ] ) ;
for ( V_52 = V_53 - 1 ; V_52 >= 0 ; V_52 -- )
F_47 ( V_5 [ V_52 ] ) ;
F_34 ( V_1 ) ;
F_35 ( V_49 ) ;
return - V_45 ;
}
static int F_48 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_49 ( V_48 ) ;
F_50 ( & V_13 ) ;
F_6 ( 1 , V_11 + V_12 ) ;
F_51 ( V_1 -> V_9 , V_1 ) ;
F_52 ( & V_1 -> V_36 ) ;
F_53 ( & V_13 ) ;
F_45 ( V_1 -> V_22 ) ;
F_34 ( V_1 ) ;
return 0 ;
}
