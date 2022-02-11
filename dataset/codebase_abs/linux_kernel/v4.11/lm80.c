static inline unsigned char F_1 ( unsigned V_1 , unsigned div )
{
if ( V_1 == 0 )
return 255 ;
V_1 = F_2 ( V_1 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_1 * div / 2 ) / ( V_1 * div ) , 1 , 254 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_4 ( V_3 , V_4 ) ;
}
static int F_5 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
return F_6 ( V_3 , V_4 , V_5 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
F_5 ( V_3 , V_6 , 0x80 ) ;
F_5 ( V_3 , V_7 , 0x08 ) ;
F_5 ( V_3 , V_6 , 0x01 ) ;
}
static struct V_8 * F_8 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_2 * V_3 = V_11 -> V_3 ;
int V_12 ;
int V_13 ;
int V_14 ;
struct V_8 * V_15 = V_11 ;
F_10 ( & V_11 -> V_16 ) ;
if ( V_11 -> error )
F_7 ( V_3 ) ;
if ( F_11 ( V_17 , V_11 -> V_18 + 2 * V_19 ) || ! V_11 -> V_20 ) {
F_12 ( V_10 , L_1 ) ;
for ( V_12 = 0 ; V_12 <= 6 ; V_12 ++ ) {
V_13 = F_3 ( V_3 , F_13 ( V_12 ) ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_21 [ V_22 ] [ V_12 ] = V_13 ;
V_13 = F_3 ( V_3 , F_14 ( V_12 ) ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_21 [ V_23 ] [ V_12 ] = V_13 ;
V_13 = F_3 ( V_3 , F_15 ( V_12 ) ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_21 [ V_24 ] [ V_12 ] = V_13 ;
}
V_13 = F_3 ( V_3 , V_25 ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_26 [ V_27 ] [ 0 ] = V_13 ;
V_13 = F_3 ( V_3 , F_16 ( 1 ) ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_26 [ V_28 ] [ 0 ] = V_13 ;
V_13 = F_3 ( V_3 , V_29 ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_26 [ V_27 ] [ 1 ] = V_13 ;
V_13 = F_3 ( V_3 , F_16 ( 2 ) ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_26 [ V_28 ] [ 1 ] = V_13 ;
V_14 = V_13 = F_3 ( V_3 , V_30 ) ;
if ( V_13 < 0 )
goto abort;
V_13 = F_3 ( V_3 , V_7 ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_31 [ V_32 ] = ( V_14 << 8 ) | ( V_13 & 0xf0 ) ;
for ( V_12 = V_32 + 1 ; V_12 < V_33 ; V_12 ++ ) {
V_13 = F_3 ( V_3 , V_34 [ V_12 ] ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_31 [ V_12 ] = V_13 << 8 ;
}
V_13 = F_3 ( V_3 , V_35 ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_36 [ 0 ] = ( V_13 >> 2 ) & 0x03 ;
V_11 -> V_36 [ 1 ] = ( V_13 >> 4 ) & 0x03 ;
V_14 = V_13 = F_3 ( V_3 , V_37 ) ;
if ( V_13 < 0 )
goto abort;
V_13 = F_3 ( V_3 , V_38 ) ;
if ( V_13 < 0 )
goto abort;
V_11 -> V_39 = V_14 + ( V_13 << 8 ) ;
V_11 -> V_18 = V_17 ;
V_11 -> V_20 = 1 ;
V_11 -> error = 0 ;
}
goto V_40;
abort:
V_15 = F_17 ( V_13 ) ;
V_11 -> V_20 = 0 ;
V_11 -> error = 1 ;
V_40:
F_18 ( & V_11 -> V_16 ) ;
return V_15 ;
}
static T_2 F_19 ( struct V_9 * V_10 , struct V_41 * V_42 ,
char * V_43 )
{
struct V_8 * V_11 = F_8 ( V_10 ) ;
int V_44 = F_20 ( V_42 ) -> V_44 ;
int V_45 = F_20 ( V_42 ) -> V_45 ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_43 , L_2 , F_23 ( V_11 -> V_21 [ V_45 ] [ V_44 ] ) ) ;
}
static T_2 F_24 ( struct V_9 * V_10 , struct V_41 * V_42 ,
const char * V_43 , T_3 V_46 )
{
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_2 * V_3 = V_11 -> V_3 ;
int V_44 = F_20 ( V_42 ) -> V_44 ;
int V_45 = F_20 ( V_42 ) -> V_45 ;
long V_47 ;
T_1 V_4 ;
int V_48 = F_25 ( V_43 , 10 , & V_47 ) ;
if ( V_48 < 0 )
return V_48 ;
V_4 = V_45 == V_23 ? F_14 ( V_44 ) : F_15 ( V_44 ) ;
F_10 ( & V_11 -> V_16 ) ;
V_11 -> V_21 [ V_45 ] [ V_44 ] = F_26 ( V_47 ) ;
F_5 ( V_3 , V_4 , V_11 -> V_21 [ V_45 ] [ V_44 ] ) ;
F_18 ( & V_11 -> V_16 ) ;
return V_46 ;
}
static T_2 F_27 ( struct V_9 * V_10 , struct V_41 * V_42 ,
char * V_43 )
{
int V_44 = F_20 ( V_42 ) -> V_44 ;
int V_45 = F_20 ( V_42 ) -> V_45 ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_43 , L_2 , F_28 ( V_11 -> V_26 [ V_45 ] [ V_44 ] ,
F_29 ( V_11 -> V_36 [ V_44 ] ) ) ) ;
}
static T_2 F_30 ( struct V_9 * V_10 , struct V_41 * V_42 ,
char * V_43 )
{
int V_45 = F_31 ( V_42 ) -> V_44 ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_43 , L_2 , F_29 ( V_11 -> V_36 [ V_45 ] ) ) ;
}
static T_2 F_32 ( struct V_9 * V_10 , struct V_41 * V_42 ,
const char * V_43 , T_3 V_46 )
{
int V_44 = F_20 ( V_42 ) -> V_44 ;
int V_45 = F_20 ( V_42 ) -> V_45 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_2 * V_3 = V_11 -> V_3 ;
unsigned long V_47 ;
int V_48 = F_33 ( V_43 , 10 , & V_47 ) ;
if ( V_48 < 0 )
return V_48 ;
F_10 ( & V_11 -> V_16 ) ;
V_11 -> V_26 [ V_45 ] [ V_44 ] = F_1 ( V_47 ,
F_29 ( V_11 -> V_36 [ V_44 ] ) ) ;
F_5 ( V_3 , F_16 ( V_44 + 1 ) ,
V_11 -> V_26 [ V_45 ] [ V_44 ] ) ;
F_18 ( & V_11 -> V_16 ) ;
return V_46 ;
}
static T_2 F_34 ( struct V_9 * V_10 , struct V_41 * V_42 ,
const char * V_43 , T_3 V_46 )
{
int V_45 = F_31 ( V_42 ) -> V_44 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_2 * V_3 = V_11 -> V_3 ;
unsigned long V_49 , V_47 ;
T_1 V_4 ;
int V_48 = F_33 ( V_43 , 10 , & V_47 ) ;
if ( V_48 < 0 )
return V_48 ;
F_10 ( & V_11 -> V_16 ) ;
V_49 = F_28 ( V_11 -> V_26 [ V_28 ] [ V_45 ] ,
F_29 ( V_11 -> V_36 [ V_45 ] ) ) ;
switch ( V_47 ) {
case 1 :
V_11 -> V_36 [ V_45 ] = 0 ;
break;
case 2 :
V_11 -> V_36 [ V_45 ] = 1 ;
break;
case 4 :
V_11 -> V_36 [ V_45 ] = 2 ;
break;
case 8 :
V_11 -> V_36 [ V_45 ] = 3 ;
break;
default:
F_35 ( V_10 ,
L_3 ,
V_47 ) ;
F_18 ( & V_11 -> V_16 ) ;
return - V_50 ;
}
V_4 = ( F_3 ( V_3 , V_35 ) &
~ ( 3 << ( 2 * ( V_45 + 1 ) ) ) ) | ( V_11 -> V_36 [ V_45 ] << ( 2 * ( V_45 + 1 ) ) ) ;
F_5 ( V_3 , V_35 , V_4 ) ;
V_11 -> V_26 [ V_28 ] [ V_45 ] = F_1 ( V_49 , F_29 ( V_11 -> V_36 [ V_45 ] ) ) ;
F_5 ( V_3 , F_16 ( V_45 + 1 ) ,
V_11 -> V_26 [ V_28 ] [ V_45 ] ) ;
F_18 ( & V_11 -> V_16 ) ;
return V_46 ;
}
static T_2 F_36 ( struct V_9 * V_10 , struct V_41 * V_51 ,
char * V_43 )
{
struct V_52 * V_42 = F_31 ( V_51 ) ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_43 , L_2 , F_37 ( V_11 -> V_31 [ V_42 -> V_44 ] ) ) ;
}
static T_2 F_38 ( struct V_9 * V_10 , struct V_41 * V_51 ,
const char * V_43 , T_3 V_46 )
{
struct V_52 * V_42 = F_31 ( V_51 ) ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_2 * V_3 = V_11 -> V_3 ;
int V_45 = V_42 -> V_44 ;
long V_47 ;
int V_48 = F_25 ( V_43 , 10 , & V_47 ) ;
if ( V_48 < 0 )
return V_48 ;
F_10 ( & V_11 -> V_16 ) ;
V_11 -> V_31 [ V_45 ] = F_39 ( V_47 ) ;
F_5 ( V_3 , V_34 [ V_45 ] , V_11 -> V_31 [ V_45 ] >> 8 ) ;
F_18 ( & V_11 -> V_16 ) ;
return V_46 ;
}
static T_2 F_40 ( struct V_9 * V_10 , struct V_41 * V_42 ,
char * V_43 )
{
struct V_8 * V_11 = F_8 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_43 , L_4 , V_11 -> V_39 ) ;
}
static T_2 F_41 ( struct V_9 * V_10 , struct V_41 * V_42 ,
char * V_43 )
{
int V_53 = F_31 ( V_42 ) -> V_44 ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_43 , L_4 , ( V_11 -> V_39 >> V_53 ) & 1 ) ;
}
static int F_42 ( struct V_2 * V_3 , struct V_54 * V_55 )
{
struct V_56 * V_57 = V_3 -> V_57 ;
int V_12 , V_58 , V_59 , V_60 ;
const char * V_61 = NULL ;
if ( ! F_43 ( V_57 , V_62 ) )
return - V_63 ;
if ( ( F_3 ( V_3 , V_38 ) & 0xc0 )
|| ( F_3 ( V_3 , V_6 ) & 0x80 ) )
return - V_63 ;
V_59 = F_3 ( V_3 , V_64 ) ;
V_60 = F_3 ( V_3 , V_65 ) ;
if ( V_59 == 0x01 && V_60 == 0x08 ) {
if ( F_3 ( V_3 , V_66 ) & 0xfe )
return - V_63 ;
V_61 = L_5 ;
} else {
for ( V_12 = 0x2a ; V_12 <= 0x3d ; V_12 ++ ) {
V_58 = F_4 ( V_3 , V_12 ) ;
if ( ( F_4 ( V_3 , V_12 + 0x40 ) != V_58 )
|| ( F_4 ( V_3 , V_12 + 0x80 ) != V_58 )
|| ( F_4 ( V_3 , V_12 + 0xc0 ) != V_58 ) )
return - V_63 ;
}
V_61 = L_6 ;
}
F_44 ( V_55 -> type , V_61 , V_67 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 ,
const struct V_68 * V_69 )
{
struct V_9 * V_10 = & V_3 -> V_10 ;
struct V_9 * V_70 ;
struct V_8 * V_11 ;
V_11 = F_46 ( V_10 , sizeof( struct V_8 ) , V_71 ) ;
if ( ! V_11 )
return - V_72 ;
V_11 -> V_3 = V_3 ;
F_47 ( & V_11 -> V_16 ) ;
F_7 ( V_3 ) ;
V_11 -> V_26 [ V_28 ] [ 0 ] = F_3 ( V_3 , F_16 ( 1 ) ) ;
V_11 -> V_26 [ V_28 ] [ 1 ] = F_3 ( V_3 , F_16 ( 2 ) ) ;
V_70 = F_48 ( V_10 , V_3 -> V_61 ,
V_11 , V_73 ) ;
return F_49 ( V_70 ) ;
}
