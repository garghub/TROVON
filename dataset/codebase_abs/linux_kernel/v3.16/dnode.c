static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
int V_7 = 1 ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
if ( V_5 == V_4 ) return ( ( T_1 ) F_5 ( V_2 -> V_8 ) << 4 ) | ( T_1 ) V_7 ;
V_7 ++ ;
}
F_6 ( L_1 , V_9 ) ;
return ( ( T_1 ) F_5 ( V_2 -> V_8 ) << 4 ) | ( T_1 ) 1 ;
}
void F_7 ( struct V_10 * V_10 , T_1 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_7 = 0 ;
T_1 * * V_14 ;
if ( V_13 -> V_15 )
for (; V_13 -> V_15 [ V_7 ] ; V_7 ++ )
if ( V_13 -> V_15 [ V_7 ] == V_11 ) return;
if ( ! ( V_7 & 0x0f ) ) {
if ( ! ( V_14 = F_9 ( ( V_7 + 0x11 ) * sizeof( T_1 * ) , V_16 ) ) ) {
F_10 ( L_2 ) ;
return;
}
if ( V_13 -> V_15 ) {
memcpy ( V_14 , V_13 -> V_15 , V_7 * sizeof( T_1 ) ) ;
F_11 ( V_13 -> V_15 ) ;
}
V_13 -> V_15 = V_14 ;
}
V_13 -> V_15 [ V_7 ] = V_11 ;
V_13 -> V_15 [ V_7 + 1 ] = NULL ;
}
void F_12 ( struct V_10 * V_10 , T_1 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
T_1 * * V_7 , * * V_17 ;
if ( ! V_13 -> V_15 ) goto V_18;
for ( V_7 = V_13 -> V_15 ; * V_7 ; V_7 ++ ) if ( * V_7 == V_11 ) goto V_19;
goto V_18;
V_19:
for ( V_17 = V_7 + 1 ; * V_17 ; V_17 ++ ) ;
* V_7 = * ( V_17 - 1 ) ;
* ( V_17 - 1 ) = NULL ;
if ( V_17 - 1 == V_13 -> V_15 ) {
F_11 ( V_13 -> V_15 ) ;
V_13 -> V_15 = NULL ;
}
return;
V_18:
return;
}
static void F_13 ( struct V_10 * V_10 , void (* F_14)( T_1 * , T_1 , T_1 ) ,
T_1 V_20 , T_1 V_21 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
T_1 * * V_7 ;
if ( ! V_13 -> V_15 ) return;
for ( V_7 = V_13 -> V_15 ; * V_7 ; V_7 ++ ) (* F_14)( * V_7 , V_20 , V_21 ) ;
return;
}
static void F_15 ( T_1 * V_22 , T_1 F_14 , T_1 V_23 )
{
if ( * V_22 == F_14 ) * V_22 = V_23 ;
}
static void F_16 ( T_1 * V_22 , T_1 V_2 , T_1 V_24 )
{
if ( ( * V_22 & ~ 0x3f ) == ( V_2 & ~ 0x3f ) && ( * V_22 & 0x3f ) >= ( V_2 & 0x3f ) ) {
int V_25 = ( * V_22 & 0x3f ) + V_24 ;
if ( V_25 > 0x3f )
F_10 ( L_3 ,
V_9 , ( int ) * V_22 , ( int ) V_24 >> 8 ) ;
else
* V_22 = ( * V_22 & ~ 0x3f ) | V_25 ;
}
}
static void F_17 ( T_1 * V_22 , T_1 V_2 , T_1 V_24 )
{
if ( ( * V_22 & ~ 0x3f ) == ( V_2 & ~ 0x3f ) && ( * V_22 & 0x3f ) >= ( V_2 & 0x3f ) ) {
int V_25 = ( * V_22 & 0x3f ) - V_24 ;
if ( V_25 < 1 )
F_10 ( L_4 ,
V_9 , ( int ) * V_22 , ( int ) V_24 >> 8 ) ;
else
* V_22 = ( * V_22 & ~ 0x3f ) | V_25 ;
}
}
static struct V_3 * F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_5 , * V_6 , * V_26 = NULL , * V_27 = NULL ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
V_27 = V_26 ; V_26 = V_5 ;
}
return V_27 ;
}
static struct V_3 * F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_5 , * V_6 , * V_26 = NULL ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
V_26 = V_5 ;
}
return V_26 ;
}
static void F_20 ( struct V_28 * V_29 , struct V_1 * V_2 , T_2 V_30 )
{
struct V_3 * V_5 ;
if ( ! ( V_5 = F_19 ( V_2 ) ) ) {
F_21 ( V_29 , L_5 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
if ( F_22 ( V_29 ) -> V_31 ) {
if ( V_5 -> V_32 ) {
F_21 ( V_29 , L_6 ,
F_5 ( V_2 -> V_8 ) , F_23 ( V_5 ) ) ;
return;
}
if ( F_24 ( V_5 -> V_33 ) != 32 ) {
F_21 ( V_29 , L_7 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
}
if ( V_30 ) {
F_25 ( & V_2 -> V_34 , 4 ) ;
if ( F_5 ( V_2 -> V_34 ) > 2048 ) {
F_21 ( V_29 , L_8 , F_5 ( V_2 -> V_8 ) ) ;
F_25 ( & V_2 -> V_34 , - 4 ) ;
return;
}
V_5 -> V_33 = F_26 ( 36 ) ;
V_5 -> V_32 = 1 ;
* ( V_35 * ) ( ( char * ) V_5 + 32 ) = F_27 ( V_30 ) ;
}
}
struct V_3 * F_28 ( struct V_28 * V_29 , struct V_1 * V_2 ,
const unsigned char * V_36 ,
unsigned V_37 , T_3 V_38 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
unsigned V_39 = F_29 ( V_37 , V_38 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_24 = F_30 ( V_29 , V_36 , V_37 , V_5 -> V_36 , V_5 -> V_37 , V_5 -> V_40 ) ;
if ( ! V_24 ) {
F_21 ( V_29 , L_9 , * V_36 , V_37 , F_5 ( V_2 -> V_8 ) ) ;
return NULL ;
}
if ( V_24 < 0 ) break;
}
memmove ( ( char * ) V_5 + V_39 , V_5 , ( char * ) V_6 - ( char * ) V_5 ) ;
memset ( V_5 , 0 , V_39 ) ;
if ( V_38 ) {
* ( V_35 * ) ( ( char * ) V_5 + V_39 - 4 ) = F_27 ( V_38 ) ;
V_5 -> V_32 = 1 ;
}
V_5 -> V_33 = F_26 ( V_39 ) ;
V_5 -> V_41 = F_31 ( V_36 , V_37 ) ;
V_5 -> V_37 = V_37 ;
memcpy ( V_5 -> V_36 , V_36 , V_37 ) ;
F_25 ( & V_2 -> V_34 , V_39 ) ;
return V_5 ;
}
static void F_32 ( struct V_28 * V_29 , struct V_1 * V_2 ,
struct V_3 * V_5 )
{
if ( V_5 -> V_40 ) {
F_21 ( V_29 , L_10 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
V_2 -> V_34 = F_27 ( F_5 ( V_2 -> V_34 ) - F_24 ( V_5 -> V_33 ) ) ;
memmove ( V_5 , F_4 ( V_5 ) , F_5 ( V_2 -> V_34 ) + ( char * ) V_2 - ( char * ) V_5 ) ;
}
static void F_33 ( struct V_28 * V_29 , struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
T_2 V_42 = F_5 ( V_2 -> V_8 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) )
if ( V_5 -> V_32 ) {
struct V_43 V_44 ;
struct V_1 * V_45 ;
if ( ( V_45 = F_34 ( V_29 , F_23 ( V_5 ) , & V_44 ) ) ) {
if ( F_5 ( V_45 -> V_46 ) != V_42 || V_45 -> V_47 ) {
V_45 -> V_46 = F_27 ( V_42 ) ;
V_45 -> V_47 = 0 ;
F_35 ( & V_44 ) ;
}
F_36 ( & V_44 ) ;
}
}
}
static int F_37 ( struct V_10 * V_7 , T_2 V_42 ,
const unsigned char * V_36 , unsigned V_37 ,
struct V_3 * V_48 , T_2 V_38 )
{
struct V_43 V_44 , V_49 , V_50 ;
struct V_1 * V_2 , * V_51 , * V_52 , * V_53 = NULL ;
T_2 V_54 , V_55 ;
struct V_3 * V_5 ;
struct V_3 V_56 ;
unsigned char * V_57 ;
int V_58 ;
int V_11 ;
struct V_59 * V_60 ;
struct V_61 * V_61 ;
int V_62 , V_63 = 0 ;
if ( ! ( V_57 = F_9 ( 256 , V_16 ) ) ) {
F_10 ( L_11 ) ;
return 1 ;
}
V_64:
if ( V_37 >= 256 ) {
F_21 ( V_7 -> V_65 , L_12 , V_9 , V_37 ) ;
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
if ( ! ( V_2 = F_34 ( V_7 -> V_65 , V_42 , & V_44 ) ) ) {
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
V_66:
if ( F_22 ( V_7 -> V_65 ) -> V_31 )
if ( F_38 ( V_7 -> V_65 , V_42 , & V_62 , & V_63 , L_13 ) ) {
F_36 ( & V_44 ) ;
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
if ( F_5 ( V_2 -> V_34 ) + F_29 ( V_37 , V_38 ) <= 2048 ) {
T_1 V_23 ;
F_39 ( V_5 = F_28 ( V_7 -> V_65 , V_2 , V_36 , V_37 , V_38 ) , V_48 ) ;
V_23 = F_1 ( V_2 , V_5 ) ;
F_13 ( V_7 , F_16 , V_23 , 1 ) ;
F_13 ( V_7 , F_15 , 4 , V_23 ) ;
F_13 ( V_7 , F_15 , 5 , V_23 + 1 ) ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 0 ;
}
if ( ! V_53 ) if ( ! ( V_53 = F_9 ( 0x924 , V_16 ) ) ) {
F_10 ( L_14 ) ;
F_36 ( & V_44 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
memcpy ( V_53 , V_2 , F_5 ( V_2 -> V_34 ) ) ;
F_39 ( V_5 = F_28 ( V_7 -> V_65 , V_53 , V_36 , V_37 , V_38 ) , V_48 ) ;
F_13 ( V_7 , F_16 , F_1 ( V_53 , V_5 ) , 1 ) ;
V_58 = ( ( char * ) F_19 ( V_53 ) - ( char * ) V_53 ) / 2 + 10 ;
if ( ! ( V_51 = F_40 ( V_7 -> V_65 , F_5 ( V_2 -> V_46 ) , & V_54 , & V_49 ) ) ) {
F_21 ( V_7 -> V_65 , L_15 ) ;
F_36 ( & V_44 ) ;
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
V_7 -> V_67 += 2048 ;
V_7 -> V_68 += 4 ;
V_11 = 1 ;
for ( V_5 = F_3 ( V_53 ) ; ( char * ) F_4 ( V_5 ) - ( char * ) V_53 < V_58 ; V_5 = F_4 ( V_5 ) ) {
F_39 ( F_28 ( V_7 -> V_65 , V_51 , V_5 -> V_36 , V_5 -> V_37 , V_5 -> V_32 ? F_23 ( V_5 ) : 0 ) , V_5 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_42 << 4 ) | V_11 , ( ( T_1 ) V_54 << 4 ) | V_11 ) ;
V_11 ++ ;
}
F_39 ( V_48 = & V_56 , V_5 ) ;
memcpy ( V_57 , V_5 -> V_36 , V_5 -> V_37 ) ;
V_36 = V_57 ;
V_37 = V_5 -> V_37 ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_42 << 4 ) | V_11 , 4 ) ;
V_38 = V_54 ;
F_20 ( V_7 -> V_65 , V_51 , V_5 -> V_32 ? F_23 ( V_5 ) : 0 ) ;
V_5 = F_4 ( V_5 ) ;
memmove ( ( char * ) V_53 + 20 , V_5 , F_5 ( V_53 -> V_34 ) + ( char * ) V_53 - ( char * ) V_5 ) ;
F_25 ( & V_53 -> V_34 , - ( ( char * ) V_5 - ( char * ) V_53 - 20 ) ) ;
memcpy ( V_2 , V_53 , F_5 ( V_53 -> V_34 ) ) ;
F_13 ( V_7 , F_17 , ( T_1 ) V_42 << 4 , V_11 ) ;
F_33 ( V_7 -> V_65 , V_51 ) ;
if ( ! V_2 -> V_47 ) {
V_51 -> V_46 = V_2 -> V_46 ;
V_42 = F_5 ( V_51 -> V_46 ) ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
goto V_64;
}
if ( ! ( V_52 = F_40 ( V_7 -> V_65 , F_5 ( V_2 -> V_46 ) , & V_55 , & V_50 ) ) ) {
F_21 ( V_7 -> V_65 , L_15 ) ;
F_36 ( & V_44 ) ;
F_36 ( & V_49 ) ;
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
V_7 -> V_67 += 2048 ;
V_7 -> V_68 += 4 ;
V_52 -> V_47 = 1 ;
V_52 -> V_46 = V_2 -> V_46 ;
if ( ! ( V_61 = F_41 ( V_7 -> V_65 , F_5 ( V_2 -> V_46 ) , & V_60 ) ) ) {
F_42 ( V_7 -> V_65 , V_55 ) ;
F_36 ( & V_44 ) ;
F_36 ( & V_49 ) ;
F_36 ( & V_50 ) ;
F_11 ( V_53 ) ;
F_11 ( V_57 ) ;
return 1 ;
}
V_61 -> V_69 . V_70 [ 0 ] . V_71 = F_27 ( V_55 ) ;
F_43 ( V_60 ) ;
F_44 ( V_60 ) ;
F_8 ( V_7 ) -> V_72 = V_55 ;
V_2 -> V_46 = V_51 -> V_46 = F_27 ( V_55 ) ;
V_2 -> V_47 = V_51 -> V_47 = 0 ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
V_44 = V_50 ;
F_20 ( V_7 -> V_65 , V_52 , V_42 ) ;
V_42 = V_55 ;
V_2 = V_52 ;
goto V_66;
}
int F_45 ( struct V_10 * V_7 ,
const unsigned char * V_36 , unsigned V_37 ,
struct V_3 * V_48 )
{
struct V_12 * V_13 = F_8 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_3 * V_5 , * V_6 ;
struct V_43 V_44 ;
T_2 V_42 ;
int V_24 ;
int V_62 , V_63 = 0 ;
V_42 = V_13 -> V_72 ;
V_32:
if ( F_22 ( V_7 -> V_65 ) -> V_31 )
if ( F_38 ( V_7 -> V_65 , V_42 , & V_62 , & V_63 , L_16 ) ) return 1 ;
if ( ! ( V_2 = F_34 ( V_7 -> V_65 , V_42 , & V_44 ) ) ) return 1 ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
if ( ! ( V_24 = F_30 ( V_7 -> V_65 , V_36 , V_37 , V_5 -> V_36 , V_5 -> V_37 , V_5 -> V_40 ) ) ) {
F_36 ( & V_44 ) ;
return - 1 ;
}
if ( V_24 < 0 ) {
if ( V_5 -> V_32 ) {
V_42 = F_23 ( V_5 ) ;
F_36 ( & V_44 ) ;
goto V_32;
}
break;
}
}
F_36 ( & V_44 ) ;
if ( F_46 ( V_7 -> V_65 , V_73 ) ) {
V_24 = 1 ;
goto V_74;
}
V_7 -> V_75 ++ ;
V_24 = F_37 ( V_7 , V_42 , V_36 , V_37 , V_48 , 0 ) ;
V_74:
return V_24 ;
}
static T_3 F_47 ( struct V_10 * V_7 , T_2 V_76 , T_2 V_77 )
{
T_2 V_42 , V_78 ;
T_2 V_79 = V_77 ;
struct V_1 * V_1 ;
struct V_43 V_44 ;
struct V_3 * V_5 , * V_56 ;
int V_80 ;
T_1 V_23 ;
int V_62 , V_63 = 0 ;
V_42 = V_76 ;
while ( 1 ) {
if ( F_22 ( V_7 -> V_65 ) -> V_31 )
if ( F_38 ( V_7 -> V_65 , V_42 , & V_62 , & V_63 , L_17 ) )
return 0 ;
if ( ! ( V_1 = F_34 ( V_7 -> V_65 , V_42 , & V_44 ) ) ) return 0 ;
if ( F_22 ( V_7 -> V_65 ) -> V_31 ) {
if ( F_5 ( V_1 -> V_46 ) != V_79 ) {
F_21 ( V_7 -> V_65 , L_18 ,
V_42 , V_79 , F_5 ( V_1 -> V_46 ) ) ;
F_36 ( & V_44 ) ;
return 0 ;
}
V_79 = V_42 ;
}
if ( ! ( V_5 = F_19 ( V_1 ) ) ) {
F_21 ( V_7 -> V_65 , L_19 , V_42 ) ;
F_36 ( & V_44 ) ;
return 0 ;
}
if ( ! V_5 -> V_32 ) break;
V_42 = F_23 ( V_5 ) ;
F_36 ( & V_44 ) ;
}
while ( ! ( V_5 = F_18 ( V_1 ) ) ) {
T_2 V_46 = F_5 ( V_1 -> V_46 ) ;
F_36 ( & V_44 ) ;
F_42 ( V_7 -> V_65 , V_42 ) ;
V_7 -> V_67 -= 2048 ;
V_7 -> V_68 -= 4 ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_42 << 4 ) | 1 , 5 ) ;
if ( V_46 == V_77 ) return V_77 ;
if ( ! ( V_1 = F_34 ( V_7 -> V_65 , V_46 , & V_44 ) ) ) return 0 ;
if ( V_1 -> V_47 ) {
F_21 ( V_7 -> V_65 , L_20 , V_76 , V_77 ) ;
F_36 ( & V_44 ) ;
return 0 ;
}
V_5 = F_19 ( V_1 ) ;
if ( ! V_5 || ! V_5 -> V_32 ) {
F_21 ( V_7 -> V_65 , L_21 , V_46 , V_42 ) ;
F_36 ( & V_44 ) ;
return 0 ;
}
F_25 ( & V_1 -> V_34 , - 4 ) ;
F_48 ( & V_5 -> V_33 , - 4 ) ;
V_5 -> V_32 = 0 ;
F_35 ( & V_44 ) ;
V_42 = V_46 ;
}
V_23 = F_1 ( V_1 , V_5 ) ;
F_13 ( V_7 , F_15 , V_23 , 4 ) ;
F_13 ( V_7 , F_15 , V_23 + 1 , 5 ) ;
if ( ! ( V_56 = F_9 ( F_24 ( V_5 -> V_33 ) , V_16 ) ) ) {
F_21 ( V_7 -> V_65 , L_22 ) ;
F_36 ( & V_44 ) ;
return 0 ;
}
memcpy ( V_56 , V_5 , F_24 ( V_5 -> V_33 ) ) ;
V_78 = V_5 -> V_32 ? F_23 ( V_5 ) : 0 ;
F_32 ( V_7 -> V_65 , V_1 , V_5 ) ;
F_20 ( V_7 -> V_65 , V_1 , V_78 ) ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
V_80 = F_37 ( V_7 , V_77 , V_56 -> V_36 , V_56 -> V_37 , V_56 , V_76 ) ;
F_11 ( V_56 ) ;
if ( V_80 ) return 0 ;
return V_42 ;
}
static void F_49 ( struct V_10 * V_7 , T_2 V_42 )
{
struct V_12 * V_13 = F_8 ( V_7 ) ;
struct V_43 V_44 ;
struct V_1 * V_1 ;
T_2 V_32 , V_46 , V_81 ;
int V_22 ;
struct V_3 * V_5 ;
int V_62 , V_63 = 0 ;
V_82:
if ( F_38 ( V_7 -> V_65 , V_42 , & V_62 , & V_63 , L_23 ) ) return;
if ( ! ( V_1 = F_34 ( V_7 -> V_65 , V_42 , & V_44 ) ) ) return;
if ( F_5 ( V_1 -> V_34 ) > 56 ) goto V_83;
if ( F_5 ( V_1 -> V_34 ) == 52 || F_5 ( V_1 -> V_34 ) == 56 ) {
struct V_3 * V_6 ;
int V_84 = V_1 -> V_47 ;
V_46 = F_5 ( V_1 -> V_46 ) ;
V_5 = F_3 ( V_1 ) ;
V_32 = V_5 -> V_32 ? F_23 ( V_5 ) : 0 ;
if ( F_22 ( V_7 -> V_65 ) -> V_31 ) if ( V_84 && ! V_32 ) {
F_21 ( V_7 -> V_65 , L_24 , V_42 ) ;
goto V_83;
}
F_36 ( & V_44 ) ;
F_42 ( V_7 -> V_65 , V_42 ) ;
V_7 -> V_67 -= 2048 ;
V_7 -> V_68 -= 4 ;
if ( V_84 ) {
struct V_61 * V_61 ;
struct V_59 * V_60 ;
struct V_1 * V_85 ;
struct V_43 V_49 ;
if ( F_22 ( V_7 -> V_65 ) -> V_31 )
if ( V_46 != V_7 -> V_86 ) {
F_21 ( V_7 -> V_65 ,
L_25 ,
V_42 , V_46 , ( unsigned long ) V_7 -> V_86 ) ;
return;
}
if ( ( V_85 = F_34 ( V_7 -> V_65 , V_32 , & V_49 ) ) ) {
V_85 -> V_46 = F_27 ( V_46 ) ;
V_85 -> V_47 = 1 ;
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
}
if ( ( V_61 = F_41 ( V_7 -> V_65 , V_46 , & V_60 ) ) ) {
V_61 -> V_69 . V_70 [ 0 ] . V_71 = F_27 ( V_32 ) ;
F_43 ( V_60 ) ;
F_44 ( V_60 ) ;
}
V_13 -> V_72 = V_32 ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_42 << 4 ) | 1 , ( T_1 ) 12 ) ;
return;
}
if ( ! ( V_1 = F_34 ( V_7 -> V_65 , V_46 , & V_44 ) ) ) return;
V_22 = 1 ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) , V_22 ++ )
if ( V_5 -> V_32 ) if ( F_23 ( V_5 ) == V_42 ) goto V_19;
F_21 ( V_7 -> V_65 , L_26 , V_42 , V_46 ) ;
goto V_83;
V_19:
F_13 ( V_7 , F_15 , ( ( T_1 ) V_42 << 4 ) | 1 , ( ( T_1 ) V_46 << 4 ) | V_22 ) ;
if ( ! V_32 ) {
V_5 -> V_32 = 0 ;
F_48 ( & V_5 -> V_33 , - 4 ) ;
F_25 ( & V_1 -> V_34 , - 4 ) ;
memmove ( F_4 ( V_5 ) , ( char * ) F_4 ( V_5 ) + 4 ,
( char * ) V_1 + F_5 ( V_1 -> V_34 ) - ( char * ) F_4 ( V_5 ) ) ;
} else {
struct V_1 * V_85 ;
struct V_43 V_49 ;
* ( T_2 * ) ( ( void * ) V_5 + F_24 ( V_5 -> V_33 ) - 4 ) = V_32 ;
if ( ( V_85 = F_34 ( V_7 -> V_65 , V_32 , & V_49 ) ) ) {
V_85 -> V_46 = F_27 ( V_46 ) ;
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
}
}
} else {
F_21 ( V_7 -> V_65 , L_27 , V_42 , F_5 ( V_1 -> V_34 ) ) ;
goto V_83;
}
if ( ! V_5 -> V_40 ) {
struct V_3 * V_87 = F_4 ( V_5 ) ;
struct V_3 * V_88 ;
struct V_1 * V_85 ;
struct V_43 V_49 ;
if ( ! V_87 -> V_32 ) goto V_89;
V_81 = F_23 ( V_87 ) ;
if ( ! ( V_88 = F_9 ( F_24 ( V_5 -> V_33 ) , V_16 ) ) ) {
F_10 ( L_28 ) ;
goto V_89;
}
memcpy ( V_88 , V_5 , F_24 ( V_5 -> V_33 ) ) ;
F_32 ( V_7 -> V_65 , V_1 , V_5 ) ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_46 << 4 ) | V_22 , 4 ) ;
F_13 ( V_7 , F_17 , ( ( T_1 ) V_46 << 4 ) | V_22 , 1 ) ;
if ( V_88 -> V_32 ) if ( ( V_85 = F_34 ( V_7 -> V_65 , F_23 ( V_88 ) , & V_49 ) ) ) {
V_85 -> V_46 = F_27 ( V_81 ) ;
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
}
F_37 ( V_7 , V_81 , V_88 -> V_36 , V_88 -> V_37 , V_88 , V_88 -> V_32 ? F_23 ( V_88 ) : 0 ) ;
V_42 = V_46 ;
F_11 ( V_88 ) ;
goto V_82;
} else {
struct V_3 * V_90 = F_18 ( V_1 ) ;
struct V_3 * V_88 ;
struct V_1 * V_85 ;
struct V_43 V_49 ;
T_2 V_91 ;
if ( ! V_90 ) {
F_21 ( V_7 -> V_65 , L_29 , V_46 ) ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
V_42 = V_46 ;
goto V_82;
}
if ( ! V_90 -> V_32 ) goto V_89;
V_81 = F_23 ( V_90 ) ;
if ( ( V_85 = F_34 ( V_7 -> V_65 , V_81 , & V_49 ) ) ) {
struct V_3 * V_92 = F_19 ( V_85 ) ;
V_91 = V_92 -> V_32 ? F_23 ( V_92 ) : 0 ;
if ( ! V_91 && V_32 ) {
if ( F_5 ( V_85 -> V_34 ) > 2044 ) {
if ( F_22 ( V_7 -> V_65 ) -> V_31 >= 2 ) {
F_10 ( L_30 ) ;
F_10 ( L_31 ) ;
}
F_36 ( & V_49 ) ;
goto V_89;
}
if ( F_22 ( V_7 -> V_65 ) -> V_31 >= 2 ) {
F_10 ( L_30 ) ;
F_10 ( L_32 ) ;
}
F_48 ( & V_92 -> V_33 , 4 ) ;
V_92 -> V_32 = 1 ;
F_25 ( & V_85 -> V_34 , 4 ) ;
}
if ( V_91 && ! V_32 ) {
F_48 ( & V_92 -> V_33 , - 4 ) ;
V_92 -> V_32 = 0 ;
F_25 ( & V_85 -> V_34 , - 4 ) ;
} else if ( V_32 )
* ( V_35 * ) ( ( void * ) V_92 + F_24 ( V_92 -> V_33 ) - 4 ) = F_27 ( V_32 ) ;
} else goto V_89;
if ( ! ( V_88 = F_9 ( F_24 ( V_90 -> V_33 ) , V_16 ) ) ) {
F_10 ( L_28 ) ;
F_36 ( & V_49 ) ;
goto V_89;
}
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
memcpy ( V_88 , V_90 , F_24 ( V_90 -> V_33 ) ) ;
F_32 ( V_7 -> V_65 , V_1 , V_90 ) ;
if ( ! V_90 -> V_32 ) {
F_48 ( & V_90 -> V_33 , 4 ) ;
V_90 -> V_32 = 1 ;
F_25 ( & V_1 -> V_34 , 4 ) ;
}
* ( V_35 * ) ( ( void * ) V_90 + F_24 ( V_90 -> V_33 ) - 4 ) = F_27 ( V_81 ) ;
F_35 ( & V_44 ) ;
F_36 ( & V_44 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_46 << 4 ) | ( V_22 - 1 ) , 4 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_46 << 4 ) | V_22 , ( ( T_1 ) V_46 << 4 ) | ( V_22 - 1 ) ) ;
if ( V_32 ) if ( ( V_85 = F_34 ( V_7 -> V_65 , F_23 ( V_5 ) , & V_49 ) ) ) {
V_85 -> V_46 = F_27 ( V_81 ) ;
F_35 ( & V_49 ) ;
F_36 ( & V_49 ) ;
}
F_37 ( V_7 , V_81 , V_88 -> V_36 , V_88 -> V_37 , V_88 , V_91 ) ;
V_42 = V_46 ;
F_11 ( V_88 ) ;
goto V_82;
}
V_89:
F_35 ( & V_44 ) ;
V_83:
F_36 ( & V_44 ) ;
}
int F_50 ( struct V_10 * V_7 , T_2 V_42 , struct V_3 * V_5 ,
struct V_43 * V_44 , int V_93 )
{
struct V_1 * V_1 = V_44 -> V_94 ;
T_2 V_32 = 0 ;
T_1 V_23 ;
if ( V_5 -> V_95 || V_5 -> V_40 ) {
F_21 ( V_7 -> V_65 , L_33 , V_42 ) ;
F_36 ( V_44 ) ;
return 1 ;
}
if ( V_5 -> V_32 ) V_32 = F_23 ( V_5 ) ;
if ( V_93 && ( V_5 -> V_32 || ( V_5 == F_3 ( V_1 ) && F_4 ( V_5 ) -> V_40 ) ) ) {
if ( F_46 ( V_7 -> V_65 , V_96 ) ) {
F_36 ( V_44 ) ;
return 2 ;
}
}
V_7 -> V_75 ++ ;
F_13 ( V_7 , F_17 , ( V_23 = F_1 ( V_1 , V_5 ) ) + 1 , 1 ) ;
F_32 ( V_7 -> V_65 , V_1 , V_5 ) ;
F_35 ( V_44 ) ;
F_36 ( V_44 ) ;
if ( V_32 ) {
T_2 V_80 = F_47 ( V_7 , V_32 , V_42 ) ;
F_13 ( V_7 , F_15 , 5 , V_23 ) ;
if ( V_80 ) F_49 ( V_7 , V_80 ) ;
return ! V_80 ;
}
F_49 ( V_7 , V_42 ) ;
return 0 ;
}
void F_51 ( struct V_28 * V_29 , T_2 V_42 , int * V_97 ,
int * V_98 , int * V_99 )
{
struct V_1 * V_1 ;
struct V_43 V_44 ;
struct V_3 * V_5 ;
T_2 V_30 , V_100 = 0 ;
int V_62 , V_63 = 0 ;
int V_85 , V_101 = 0 ;
V_102:
if ( V_97 ) ( * V_97 ) ++ ;
if ( F_22 ( V_29 ) -> V_31 )
if ( F_38 ( V_29 , V_42 , & V_62 , & V_63 , L_34 ) ) return;
V_30 = 0 ;
V_64:
if ( ! ( V_1 = F_34 ( V_29 , V_42 , & V_44 ) ) ) return;
if ( F_22 ( V_29 ) -> V_31 ) if ( V_100 && V_100 != - 1 && F_5 ( V_1 -> V_46 ) != V_100 )
F_21 ( V_29 , L_35 , V_100 , V_42 , F_5 ( V_1 -> V_46 ) ) ;
V_5 = F_3 ( V_1 ) ;
if ( V_30 ) while( 1 ) {
if ( V_5 -> V_32 ) if ( F_23 ( V_5 ) == V_30 ) goto V_103;
if ( V_5 -> V_40 ) {
F_36 ( & V_44 ) ;
F_21 ( V_29 , L_36 ,
V_30 , V_42 , V_100 ) ;
return;
}
V_5 = F_4 ( V_5 ) ;
}
V_104:
if ( V_5 -> V_32 ) {
V_100 = V_42 ;
V_42 = F_23 ( V_5 ) ;
F_36 ( & V_44 ) ;
goto V_102;
}
V_103:
if ( ! V_5 -> V_95 && ! V_5 -> V_40 && V_5 -> V_105 && V_98 ) ( * V_98 ) ++ ;
if ( ! V_5 -> V_95 && ! V_5 -> V_40 && V_99 ) ( * V_99 ) ++ ;
if ( ( V_5 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) goto V_104;
V_30 = V_42 ;
V_42 = F_5 ( V_1 -> V_46 ) ;
if ( V_1 -> V_47 ) {
F_36 ( & V_44 ) ;
return;
}
F_36 ( & V_44 ) ;
if ( F_22 ( V_29 ) -> V_31 )
if ( F_38 ( V_29 , V_30 , & V_85 , & V_101 , L_37 ) ) return;
V_100 = - 1 ;
goto V_64;
}
static struct V_3 * F_52 ( struct V_28 * V_29 , T_2 V_42 , int V_25 ,
struct V_43 * V_44 , struct V_1 * * V_106 )
{
int V_7 ;
struct V_3 * V_5 , * V_6 ;
struct V_1 * V_1 ;
V_1 = F_34 ( V_29 , V_42 , V_44 ) ;
if ( ! V_1 ) return NULL ;
if ( V_106 ) * V_106 = V_1 ;
V_5 = F_3 ( V_1 ) ;
V_6 = F_2 ( V_1 ) ;
for ( V_7 = 1 ; V_5 < V_6 ; V_7 ++ , V_5 = F_4 ( V_5 ) ) {
if ( V_7 == V_25 ) {
return V_5 ;
}
if ( V_5 -> V_40 ) break;
}
F_36 ( V_44 ) ;
F_21 ( V_29 , L_38 , V_42 , V_25 ) ;
return NULL ;
}
T_2 F_53 ( struct V_28 * V_29 , T_2 V_42 )
{
struct V_43 V_44 ;
T_2 V_2 = V_42 ;
T_2 V_46 = 0 ;
struct V_3 * V_5 ;
int V_62 , V_63 = 0 ;
V_107:
if ( F_22 ( V_29 ) -> V_31 )
if ( F_38 ( V_29 , V_2 , & V_62 , & V_63 , L_39 ) )
return V_2 ;
if ( ! ( V_5 = F_52 ( V_29 , V_2 , 1 , & V_44 , NULL ) ) ) return V_42 ;
if ( F_22 ( V_29 ) -> V_31 )
if ( V_46 && F_5 ( ( (struct V_1 * ) V_44 . V_94 ) -> V_46 ) != V_46 )
F_21 ( V_29 , L_40 , V_46 , V_2 , F_5 ( ( (struct V_1 * ) V_44 . V_94 ) -> V_46 ) ) ;
if ( ! V_5 -> V_32 ) {
F_36 ( & V_44 ) ;
return V_2 ;
}
V_46 = V_2 ;
V_2 = F_23 ( V_5 ) ;
F_36 ( & V_44 ) ;
goto V_107;
}
struct V_3 * F_54 ( struct V_10 * V_10 , T_1 * V_108 ,
struct V_43 * V_44 )
{
T_1 V_11 ;
unsigned V_24 ;
T_2 V_42 ;
struct V_3 * V_5 , * V_2 ;
struct V_3 * V_109 ;
struct V_3 * V_110 ;
struct V_1 * V_1 ;
struct V_1 * V_111 ;
struct V_43 V_112 ;
V_11 = * V_108 ;
V_42 = V_11 >> 6 << 2 ;
V_11 &= 077 ;
if ( ! ( V_5 = F_52 ( V_10 -> V_65 , V_42 , V_11 , V_44 , & V_1 ) ) )
goto V_113;
if ( ( V_2 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) {
if ( ! ( ++ * V_108 & 077 ) ) {
F_21 ( V_10 -> V_65 ,
L_41 ,
( unsigned long long ) * V_108 ) ;
goto V_113;
}
if ( V_2 -> V_32 ) {
* V_108 = ( ( T_1 ) F_53 ( V_10 -> V_65 , F_23 ( V_2 ) ) << 4 ) + 1 ;
}
return V_5 ;
}
if ( V_1 -> V_47 ) goto V_113;
if ( ! ( V_111 = F_34 ( V_10 -> V_65 , F_5 ( V_1 -> V_46 ) , & V_112 ) ) )
goto V_113;
V_110 = F_2 ( V_111 ) ;
V_24 = 0 ;
for ( V_109 = F_3 ( V_111 ) ; V_109 < V_110 ;
V_109 = F_4 ( V_109 ) ) {
if ( ! ( ++ V_24 & 077 ) ) F_21 ( V_10 -> V_65 ,
L_42 , F_5 ( V_1 -> V_46 ) ) ;
if ( V_109 -> V_32 && F_23 ( V_109 ) == V_42 ) {
* V_108 = ( ( T_1 ) F_5 ( V_1 -> V_46 ) << 4 ) + V_24 ;
F_36 ( & V_112 ) ;
return V_5 ;
}
}
F_21 ( V_10 -> V_65 , L_43 ,
V_42 , F_5 ( V_1 -> V_46 ) ) ;
F_36 ( & V_112 ) ;
V_113:
* V_108 = 12 ;
return V_5 ;
}
struct V_3 * F_55 ( struct V_10 * V_10 , T_2 V_42 ,
const unsigned char * V_36 , unsigned V_114 ,
T_2 * V_45 , struct V_43 * V_44 )
{
struct V_1 * V_1 ;
struct V_3 * V_5 ;
struct V_3 * V_6 ;
int V_62 , V_63 = 0 ;
if ( ! F_56 ( V_10 -> V_115 ) ) F_21 ( V_10 -> V_65 , L_44 ) ;
V_107:
if ( F_22 ( V_10 -> V_65 ) -> V_31 )
if ( F_38 ( V_10 -> V_65 , V_42 , & V_62 , & V_63 , L_45 ) ) return NULL ;
if ( ! ( V_1 = F_34 ( V_10 -> V_65 , V_42 , V_44 ) ) ) return NULL ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_23 = F_30 ( V_10 -> V_65 , V_36 , V_114 , V_5 -> V_36 , V_5 -> V_37 , V_5 -> V_40 ) ;
if ( ! V_23 ) {
if ( V_45 ) * V_45 = V_42 ;
return V_5 ;
}
if ( V_23 < 0 ) {
if ( V_5 -> V_32 ) {
V_42 = F_23 ( V_5 ) ;
F_36 ( V_44 ) ;
goto V_107;
}
break;
}
}
F_36 ( V_44 ) ;
return NULL ;
}
void F_57 ( struct V_28 * V_29 , T_2 V_42 )
{
struct V_43 V_44 ;
struct V_1 * V_1 ;
struct V_3 * V_5 ;
T_2 V_85 , V_101 , V_55 = V_42 ;
while ( 1 ) {
if ( ! ( V_1 = F_34 ( V_29 , V_42 , & V_44 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( V_5 -> V_40 ) {
if ( V_5 -> V_32 ) V_85 = F_23 ( V_5 ) ;
else goto error;
F_36 ( & V_44 ) ;
F_42 ( V_29 , V_42 ) ;
V_42 = V_85 ;
} else break;
}
if ( ! V_5 -> V_95 ) goto error;
V_85 = V_5 -> V_32 ? F_23 ( V_5 ) : 0 ;
V_5 = F_4 ( V_5 ) ;
if ( ! V_5 -> V_40 ) goto error;
V_101 = V_5 -> V_32 ? F_23 ( V_5 ) : 0 ;
F_36 ( & V_44 ) ;
F_42 ( V_29 , V_42 ) ;
do {
while ( V_85 ) {
if ( ! ( V_1 = F_34 ( V_29 , V_42 = V_85 , & V_44 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( ! V_5 -> V_40 ) goto error;
V_85 = V_5 -> V_32 ? F_23 ( V_5 ) : 0 ;
F_36 ( & V_44 ) ;
F_42 ( V_29 , V_42 ) ;
}
V_85 = V_101 ;
V_101 = 0 ;
} while ( V_85 );
return;
error:
F_36 ( & V_44 ) ;
F_42 ( V_29 , V_42 ) ;
F_21 ( V_29 , L_46 , V_55 ) ;
}
struct V_3 * F_58 ( struct V_28 * V_29 , T_4 V_116 ,
struct V_61 * F_14 , struct V_43 * V_44 )
{
unsigned char * V_117 ;
unsigned char * V_118 ;
int V_119 , V_120 ;
struct V_1 * V_2 ;
T_2 V_42 , V_121 ;
struct V_61 * V_122 ;
struct V_59 * V_60 ;
struct V_3 * V_5 , * V_6 ;
int V_24 ;
int V_62 , V_63 = 0 ;
int V_85 , V_101 = 0 ;
V_117 = F_14 -> V_36 ;
if ( ! ( V_118 = F_9 ( 256 , V_16 ) ) ) {
F_10 ( L_47 ) ;
return NULL ;
}
if ( F_14 -> V_114 <= 15 )
memcpy ( V_118 , V_117 , V_119 = V_120 = F_14 -> V_114 ) ;
else {
memcpy ( V_118 , V_117 , 15 ) ;
memset ( V_118 + 15 , 0xff , 256 - 15 ) ;
V_119 = 15 ; V_120 = 256 ;
}
if ( ! ( V_122 = F_41 ( V_29 , F_5 ( F_14 -> V_46 ) , & V_60 ) ) ) {
F_11 ( V_118 ) ;
return NULL ;
}
if ( ! F_59 ( V_122 ) ) {
F_44 ( V_60 ) ;
F_21 ( V_29 , L_48 , V_116 , F_5 ( F_14 -> V_46 ) ) ;
F_11 ( V_118 ) ;
return NULL ;
}
V_42 = F_5 ( V_122 -> V_69 . V_70 [ 0 ] . V_71 ) ;
F_44 ( V_60 ) ;
V_102:
V_121 = 0 ;
V_64:
if ( ! ( V_2 = F_34 ( V_29 , V_42 , V_44 ) ) ) {
F_11 ( V_118 ) ;
return NULL ;
}
V_6 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_2 ) ;
if ( V_121 ) {
while ( V_5 < V_6 ) {
if ( V_5 -> V_32 ) if ( F_23 ( V_5 ) == V_121 ) goto F_14;
V_5 = F_4 ( V_5 ) ;
}
F_21 ( V_29 , L_49 , V_121 , V_42 ) ;
F_36 ( V_44 ) ;
F_11 ( V_118 ) ;
return NULL ;
}
V_104:
if ( F_5 ( V_5 -> V_61 ) == V_116 ) {
F_11 ( V_118 ) ;
return V_5 ;
}
V_24 = F_30 ( V_29 , V_117 , V_119 , V_5 -> V_36 , V_5 -> V_37 , V_5 -> V_40 ) ;
if ( V_24 < 0 && V_5 -> V_32 ) {
V_42 = F_23 ( V_5 ) ;
F_36 ( V_44 ) ;
if ( F_22 ( V_29 ) -> V_31 )
if ( F_38 ( V_29 , V_42 , & V_62 , & V_63 , L_50 ) ) {
F_11 ( V_118 ) ;
return NULL ;
}
goto V_102;
}
F_14:
if ( F_5 ( V_5 -> V_61 ) == V_116 ) {
F_11 ( V_118 ) ;
return V_5 ;
}
V_24 = F_30 ( V_29 , V_118 , V_120 , V_5 -> V_36 , V_5 -> V_37 , V_5 -> V_40 ) ;
if ( V_24 < 0 && ! V_5 -> V_40 ) goto V_123;
if ( ( V_5 = F_4 ( V_5 ) ) < V_6 ) goto V_104;
if ( V_2 -> V_47 ) goto V_123;
V_121 = V_42 ;
V_42 = F_5 ( V_2 -> V_46 ) ;
F_36 ( V_44 ) ;
if ( F_22 ( V_29 ) -> V_31 )
if ( F_38 ( V_29 , V_121 , & V_85 , & V_101 , L_51 ) ) {
F_11 ( V_118 ) ;
return NULL ;
}
goto V_64;
V_123:
F_36 ( V_44 ) ;
F_21 ( V_29 , L_52 , V_116 ) ;
F_11 ( V_118 ) ;
return NULL ;
}
