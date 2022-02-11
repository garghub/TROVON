static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
int V_7 = 1 ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
if ( V_5 == V_4 ) return ( ( T_1 ) F_5 ( V_2 -> V_8 ) << 4 ) | ( T_1 ) V_7 ;
V_7 ++ ;
}
F_6 ( L_1 ) ;
return ( ( T_1 ) F_5 ( V_2 -> V_8 ) << 4 ) | ( T_1 ) 1 ;
}
void F_7 ( struct V_9 * V_9 , T_1 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_7 = 0 ;
T_1 * * V_13 ;
if ( V_12 -> V_14 )
for (; V_12 -> V_14 [ V_7 ] ; V_7 ++ )
if ( V_12 -> V_14 [ V_7 ] == V_10 ) return;
if ( ! ( V_7 & 0x0f ) ) {
if ( ! ( V_13 = F_9 ( ( V_7 + 0x11 ) * sizeof( T_1 * ) , V_15 ) ) ) {
F_6 ( L_2 ) ;
return;
}
if ( V_12 -> V_14 ) {
memcpy ( V_13 , V_12 -> V_14 , V_7 * sizeof( T_1 ) ) ;
F_10 ( V_12 -> V_14 ) ;
}
V_12 -> V_14 = V_13 ;
}
V_12 -> V_14 [ V_7 ] = V_10 ;
V_12 -> V_14 [ V_7 + 1 ] = NULL ;
}
void F_11 ( struct V_9 * V_9 , T_1 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
T_1 * * V_7 , * * V_16 ;
if ( ! V_12 -> V_14 ) goto V_17;
for ( V_7 = V_12 -> V_14 ; * V_7 ; V_7 ++ ) if ( * V_7 == V_10 ) goto V_18;
goto V_17;
V_18:
for ( V_16 = V_7 + 1 ; * V_16 ; V_16 ++ ) ;
* V_7 = * ( V_16 - 1 ) ;
* ( V_16 - 1 ) = NULL ;
if ( V_16 - 1 == V_12 -> V_14 ) {
F_10 ( V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
}
return;
V_17:
return;
}
static void F_12 ( struct V_9 * V_9 , void (* F_13)( T_1 * , T_1 , T_1 ) ,
T_1 V_19 , T_1 V_20 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
T_1 * * V_7 ;
if ( ! V_12 -> V_14 ) return;
for ( V_7 = V_12 -> V_14 ; * V_7 ; V_7 ++ ) (* F_13)( * V_7 , V_19 , V_20 ) ;
return;
}
static void F_14 ( T_1 * V_21 , T_1 F_13 , T_1 V_22 )
{
if ( * V_21 == F_13 ) * V_21 = V_22 ;
}
static void F_15 ( T_1 * V_21 , T_1 V_2 , T_1 V_23 )
{
if ( ( * V_21 & ~ 0x3f ) == ( V_2 & ~ 0x3f ) && ( * V_21 & 0x3f ) >= ( V_2 & 0x3f ) ) {
int V_24 = ( * V_21 & 0x3f ) + V_23 ;
if ( V_24 > 0x3f ) F_6 ( L_3 , ( int ) * V_21 , ( int ) V_23 >> 8 ) ;
else * V_21 = ( * V_21 & ~ 0x3f ) | V_24 ;
}
}
static void F_16 ( T_1 * V_21 , T_1 V_2 , T_1 V_23 )
{
if ( ( * V_21 & ~ 0x3f ) == ( V_2 & ~ 0x3f ) && ( * V_21 & 0x3f ) >= ( V_2 & 0x3f ) ) {
int V_24 = ( * V_21 & 0x3f ) - V_23 ;
if ( V_24 < 1 ) F_6 ( L_4 , ( int ) * V_21 , ( int ) V_23 >> 8 ) ;
else * V_21 = ( * V_21 & ~ 0x3f ) | V_24 ;
}
}
static struct V_3 * F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_5 , * V_6 , * V_25 = NULL , * V_26 = NULL ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
V_26 = V_25 ; V_25 = V_5 ;
}
return V_26 ;
}
static struct V_3 * F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_5 , * V_6 , * V_25 = NULL ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
V_25 = V_5 ;
}
return V_25 ;
}
static void F_19 ( struct V_27 * V_28 , struct V_1 * V_2 , T_2 V_29 )
{
struct V_3 * V_5 ;
if ( ! ( V_5 = F_18 ( V_2 ) ) ) {
F_20 ( V_28 , L_5 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
if ( F_21 ( V_28 ) -> V_30 ) {
if ( V_5 -> V_31 ) {
F_20 ( V_28 , L_6 ,
F_5 ( V_2 -> V_8 ) , F_22 ( V_5 ) ) ;
return;
}
if ( F_23 ( V_5 -> V_32 ) != 32 ) {
F_20 ( V_28 , L_7 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
}
if ( V_29 ) {
F_24 ( & V_2 -> V_33 , 4 ) ;
if ( F_5 ( V_2 -> V_33 ) > 2048 ) {
F_20 ( V_28 , L_8 , F_5 ( V_2 -> V_8 ) ) ;
F_24 ( & V_2 -> V_33 , - 4 ) ;
return;
}
V_5 -> V_32 = F_25 ( 36 ) ;
V_5 -> V_31 = 1 ;
* ( V_34 * ) ( ( char * ) V_5 + 32 ) = F_26 ( V_29 ) ;
}
}
struct V_3 * F_27 ( struct V_27 * V_28 , struct V_1 * V_2 ,
const unsigned char * V_35 ,
unsigned V_36 , T_3 V_37 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
unsigned V_38 = F_28 ( V_36 , V_37 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_23 = F_29 ( V_28 , V_35 , V_36 , V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_39 ) ;
if ( ! V_23 ) {
F_20 ( V_28 , L_9 , * V_35 , V_36 , F_5 ( V_2 -> V_8 ) ) ;
return NULL ;
}
if ( V_23 < 0 ) break;
}
memmove ( ( char * ) V_5 + V_38 , V_5 , ( char * ) V_6 - ( char * ) V_5 ) ;
memset ( V_5 , 0 , V_38 ) ;
if ( V_37 ) {
* ( V_34 * ) ( ( char * ) V_5 + V_38 - 4 ) = F_26 ( V_37 ) ;
V_5 -> V_31 = 1 ;
}
V_5 -> V_32 = F_25 ( V_38 ) ;
V_5 -> V_40 = F_30 ( V_35 , V_36 ) ;
V_5 -> V_36 = V_36 ;
memcpy ( V_5 -> V_35 , V_35 , V_36 ) ;
F_24 ( & V_2 -> V_33 , V_38 ) ;
return V_5 ;
}
static void F_31 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_3 * V_5 )
{
if ( V_5 -> V_39 ) {
F_20 ( V_28 , L_10 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
V_2 -> V_33 = F_26 ( F_5 ( V_2 -> V_33 ) - F_23 ( V_5 -> V_32 ) ) ;
memmove ( V_5 , F_4 ( V_5 ) , F_5 ( V_2 -> V_33 ) + ( char * ) V_2 - ( char * ) V_5 ) ;
}
static void F_32 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
T_2 V_41 = F_5 ( V_2 -> V_8 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) )
if ( V_5 -> V_31 ) {
struct V_42 V_43 ;
struct V_1 * V_44 ;
if ( ( V_44 = F_33 ( V_28 , F_22 ( V_5 ) , & V_43 ) ) ) {
if ( F_5 ( V_44 -> V_45 ) != V_41 || V_44 -> V_46 ) {
V_44 -> V_45 = F_26 ( V_41 ) ;
V_44 -> V_46 = 0 ;
F_34 ( & V_43 ) ;
}
F_35 ( & V_43 ) ;
}
}
}
static int F_36 ( struct V_9 * V_7 , T_2 V_41 ,
const unsigned char * V_35 , unsigned V_36 ,
struct V_3 * V_47 , T_2 V_37 )
{
struct V_42 V_43 , V_48 , V_49 ;
struct V_1 * V_2 , * V_50 , * V_51 , * V_52 = NULL ;
T_2 V_53 , V_54 ;
struct V_3 * V_5 ;
struct V_3 V_55 ;
unsigned char * V_56 ;
int V_57 ;
int V_10 ;
struct V_58 * V_59 ;
struct V_60 * V_60 ;
int V_61 , V_62 = 0 ;
if ( ! ( V_56 = F_9 ( 256 , V_15 ) ) ) {
F_6 ( L_11 ) ;
return 1 ;
}
V_63:
if ( V_36 >= 256 ) {
F_20 ( V_7 -> V_64 , L_12 , V_36 ) ;
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
if ( ! ( V_2 = F_33 ( V_7 -> V_64 , V_41 , & V_43 ) ) ) {
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
V_65:
if ( F_21 ( V_7 -> V_64 ) -> V_30 )
if ( F_37 ( V_7 -> V_64 , V_41 , & V_61 , & V_62 , L_13 ) ) {
F_35 ( & V_43 ) ;
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
if ( F_5 ( V_2 -> V_33 ) + F_28 ( V_36 , V_37 ) <= 2048 ) {
T_1 V_22 ;
F_38 ( V_5 = F_27 ( V_7 -> V_64 , V_2 , V_35 , V_36 , V_37 ) , V_47 ) ;
V_22 = F_1 ( V_2 , V_5 ) ;
F_12 ( V_7 , F_15 , V_22 , 1 ) ;
F_12 ( V_7 , F_14 , 4 , V_22 ) ;
F_12 ( V_7 , F_14 , 5 , V_22 + 1 ) ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 0 ;
}
if ( ! V_52 ) if ( ! ( V_52 = F_9 ( 0x924 , V_15 ) ) ) {
F_6 ( L_14 ) ;
F_35 ( & V_43 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
memcpy ( V_52 , V_2 , F_5 ( V_2 -> V_33 ) ) ;
F_38 ( V_5 = F_27 ( V_7 -> V_64 , V_52 , V_35 , V_36 , V_37 ) , V_47 ) ;
F_12 ( V_7 , F_15 , F_1 ( V_52 , V_5 ) , 1 ) ;
V_57 = ( ( char * ) F_18 ( V_52 ) - ( char * ) V_52 ) / 2 + 10 ;
if ( ! ( V_50 = F_39 ( V_7 -> V_64 , F_5 ( V_2 -> V_45 ) , & V_53 , & V_48 ) ) ) {
F_20 ( V_7 -> V_64 , L_15 ) ;
F_35 ( & V_43 ) ;
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
V_7 -> V_66 += 2048 ;
V_7 -> V_67 += 4 ;
V_10 = 1 ;
for ( V_5 = F_3 ( V_52 ) ; ( char * ) F_4 ( V_5 ) - ( char * ) V_52 < V_57 ; V_5 = F_4 ( V_5 ) ) {
F_38 ( F_27 ( V_7 -> V_64 , V_50 , V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_31 ? F_22 ( V_5 ) : 0 ) , V_5 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_41 << 4 ) | V_10 , ( ( T_1 ) V_53 << 4 ) | V_10 ) ;
V_10 ++ ;
}
F_38 ( V_47 = & V_55 , V_5 ) ;
memcpy ( V_56 , V_5 -> V_35 , V_5 -> V_36 ) ;
V_35 = V_56 ;
V_36 = V_5 -> V_36 ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_41 << 4 ) | V_10 , 4 ) ;
V_37 = V_53 ;
F_19 ( V_7 -> V_64 , V_50 , V_5 -> V_31 ? F_22 ( V_5 ) : 0 ) ;
V_5 = F_4 ( V_5 ) ;
memmove ( ( char * ) V_52 + 20 , V_5 , F_5 ( V_52 -> V_33 ) + ( char * ) V_52 - ( char * ) V_5 ) ;
F_24 ( & V_52 -> V_33 , - ( ( char * ) V_5 - ( char * ) V_52 - 20 ) ) ;
memcpy ( V_2 , V_52 , F_5 ( V_52 -> V_33 ) ) ;
F_12 ( V_7 , F_16 , ( T_1 ) V_41 << 4 , V_10 ) ;
F_32 ( V_7 -> V_64 , V_50 ) ;
if ( ! V_2 -> V_46 ) {
V_50 -> V_45 = V_2 -> V_45 ;
V_41 = F_5 ( V_50 -> V_45 ) ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
goto V_63;
}
if ( ! ( V_51 = F_39 ( V_7 -> V_64 , F_5 ( V_2 -> V_45 ) , & V_54 , & V_49 ) ) ) {
F_20 ( V_7 -> V_64 , L_15 ) ;
F_35 ( & V_43 ) ;
F_35 ( & V_48 ) ;
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
V_7 -> V_66 += 2048 ;
V_7 -> V_67 += 4 ;
V_51 -> V_46 = 1 ;
V_51 -> V_45 = V_2 -> V_45 ;
if ( ! ( V_60 = F_40 ( V_7 -> V_64 , F_5 ( V_2 -> V_45 ) , & V_59 ) ) ) {
F_41 ( V_7 -> V_64 , V_54 ) ;
F_35 ( & V_43 ) ;
F_35 ( & V_48 ) ;
F_35 ( & V_49 ) ;
F_10 ( V_52 ) ;
F_10 ( V_56 ) ;
return 1 ;
}
V_60 -> V_68 . V_69 [ 0 ] . V_70 = F_26 ( V_54 ) ;
F_42 ( V_59 ) ;
F_43 ( V_59 ) ;
F_8 ( V_7 ) -> V_71 = V_54 ;
V_2 -> V_45 = V_50 -> V_45 = F_26 ( V_54 ) ;
V_2 -> V_46 = V_50 -> V_46 = 0 ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
V_43 = V_49 ;
F_19 ( V_7 -> V_64 , V_51 , V_41 ) ;
V_41 = V_54 ;
V_2 = V_51 ;
goto V_65;
}
int F_44 ( struct V_9 * V_7 ,
const unsigned char * V_35 , unsigned V_36 ,
struct V_3 * V_47 )
{
struct V_11 * V_12 = F_8 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_3 * V_5 , * V_6 ;
struct V_42 V_43 ;
T_2 V_41 ;
int V_23 ;
int V_61 , V_62 = 0 ;
V_41 = V_12 -> V_71 ;
V_31:
if ( F_21 ( V_7 -> V_64 ) -> V_30 )
if ( F_37 ( V_7 -> V_64 , V_41 , & V_61 , & V_62 , L_16 ) ) return 1 ;
if ( ! ( V_2 = F_33 ( V_7 -> V_64 , V_41 , & V_43 ) ) ) return 1 ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
if ( ! ( V_23 = F_29 ( V_7 -> V_64 , V_35 , V_36 , V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_39 ) ) ) {
F_35 ( & V_43 ) ;
return - 1 ;
}
if ( V_23 < 0 ) {
if ( V_5 -> V_31 ) {
V_41 = F_22 ( V_5 ) ;
F_35 ( & V_43 ) ;
goto V_31;
}
break;
}
}
F_35 ( & V_43 ) ;
if ( F_45 ( V_7 -> V_64 , V_72 ) ) {
V_23 = 1 ;
goto V_73;
}
V_7 -> V_74 ++ ;
V_23 = F_36 ( V_7 , V_41 , V_35 , V_36 , V_47 , 0 ) ;
V_73:
return V_23 ;
}
static T_3 F_46 ( struct V_9 * V_7 , T_2 V_75 , T_2 V_76 )
{
T_2 V_41 , V_77 ;
T_2 V_78 = V_76 ;
struct V_1 * V_1 ;
struct V_42 V_43 ;
struct V_3 * V_5 , * V_55 ;
int V_79 ;
T_1 V_22 ;
int V_61 , V_62 = 0 ;
V_41 = V_75 ;
while ( 1 ) {
if ( F_21 ( V_7 -> V_64 ) -> V_30 )
if ( F_37 ( V_7 -> V_64 , V_41 , & V_61 , & V_62 , L_17 ) )
return 0 ;
if ( ! ( V_1 = F_33 ( V_7 -> V_64 , V_41 , & V_43 ) ) ) return 0 ;
if ( F_21 ( V_7 -> V_64 ) -> V_30 ) {
if ( F_5 ( V_1 -> V_45 ) != V_78 ) {
F_20 ( V_7 -> V_64 , L_18 ,
V_41 , V_78 , F_5 ( V_1 -> V_45 ) ) ;
F_35 ( & V_43 ) ;
return 0 ;
}
V_78 = V_41 ;
}
if ( ! ( V_5 = F_18 ( V_1 ) ) ) {
F_20 ( V_7 -> V_64 , L_19 , V_41 ) ;
F_35 ( & V_43 ) ;
return 0 ;
}
if ( ! V_5 -> V_31 ) break;
V_41 = F_22 ( V_5 ) ;
F_35 ( & V_43 ) ;
}
while ( ! ( V_5 = F_17 ( V_1 ) ) ) {
T_2 V_45 = F_5 ( V_1 -> V_45 ) ;
F_35 ( & V_43 ) ;
F_41 ( V_7 -> V_64 , V_41 ) ;
V_7 -> V_66 -= 2048 ;
V_7 -> V_67 -= 4 ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_41 << 4 ) | 1 , 5 ) ;
if ( V_45 == V_76 ) return V_76 ;
if ( ! ( V_1 = F_33 ( V_7 -> V_64 , V_45 , & V_43 ) ) ) return 0 ;
if ( V_1 -> V_46 ) {
F_20 ( V_7 -> V_64 , L_20 , V_75 , V_76 ) ;
F_35 ( & V_43 ) ;
return 0 ;
}
V_5 = F_18 ( V_1 ) ;
if ( ! V_5 || ! V_5 -> V_31 ) {
F_20 ( V_7 -> V_64 , L_21 , V_45 , V_41 ) ;
F_35 ( & V_43 ) ;
return 0 ;
}
F_24 ( & V_1 -> V_33 , - 4 ) ;
F_47 ( & V_5 -> V_32 , - 4 ) ;
V_5 -> V_31 = 0 ;
F_34 ( & V_43 ) ;
V_41 = V_45 ;
}
V_22 = F_1 ( V_1 , V_5 ) ;
F_12 ( V_7 , F_14 , V_22 , 4 ) ;
F_12 ( V_7 , F_14 , V_22 + 1 , 5 ) ;
if ( ! ( V_55 = F_9 ( F_23 ( V_5 -> V_32 ) , V_15 ) ) ) {
F_20 ( V_7 -> V_64 , L_22 ) ;
F_35 ( & V_43 ) ;
return 0 ;
}
memcpy ( V_55 , V_5 , F_23 ( V_5 -> V_32 ) ) ;
V_77 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
F_31 ( V_7 -> V_64 , V_1 , V_5 ) ;
F_19 ( V_7 -> V_64 , V_1 , V_77 ) ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
V_79 = F_36 ( V_7 , V_76 , V_55 -> V_35 , V_55 -> V_36 , V_55 , V_75 ) ;
F_10 ( V_55 ) ;
if ( V_79 ) return 0 ;
return V_41 ;
}
static void F_48 ( struct V_9 * V_7 , T_2 V_41 )
{
struct V_11 * V_12 = F_8 ( V_7 ) ;
struct V_42 V_43 ;
struct V_1 * V_1 ;
T_2 V_31 , V_45 , V_80 ;
int V_21 ;
struct V_3 * V_5 ;
int V_61 , V_62 = 0 ;
V_81:
if ( F_37 ( V_7 -> V_64 , V_41 , & V_61 , & V_62 , L_23 ) ) return;
if ( ! ( V_1 = F_33 ( V_7 -> V_64 , V_41 , & V_43 ) ) ) return;
if ( F_5 ( V_1 -> V_33 ) > 56 ) goto V_82;
if ( F_5 ( V_1 -> V_33 ) == 52 || F_5 ( V_1 -> V_33 ) == 56 ) {
struct V_3 * V_6 ;
int V_83 = V_1 -> V_46 ;
V_45 = F_5 ( V_1 -> V_45 ) ;
V_5 = F_3 ( V_1 ) ;
V_31 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
if ( F_21 ( V_7 -> V_64 ) -> V_30 ) if ( V_83 && ! V_31 ) {
F_20 ( V_7 -> V_64 , L_24 , V_41 ) ;
goto V_82;
}
F_35 ( & V_43 ) ;
F_41 ( V_7 -> V_64 , V_41 ) ;
V_7 -> V_66 -= 2048 ;
V_7 -> V_67 -= 4 ;
if ( V_83 ) {
struct V_60 * V_60 ;
struct V_58 * V_59 ;
struct V_1 * V_84 ;
struct V_42 V_48 ;
if ( F_21 ( V_7 -> V_64 ) -> V_30 )
if ( V_45 != V_7 -> V_85 ) {
F_20 ( V_7 -> V_64 ,
L_25 ,
V_41 , V_45 , ( unsigned long ) V_7 -> V_85 ) ;
return;
}
if ( ( V_84 = F_33 ( V_7 -> V_64 , V_31 , & V_48 ) ) ) {
V_84 -> V_45 = F_26 ( V_45 ) ;
V_84 -> V_46 = 1 ;
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
}
if ( ( V_60 = F_40 ( V_7 -> V_64 , V_45 , & V_59 ) ) ) {
V_60 -> V_68 . V_69 [ 0 ] . V_70 = F_26 ( V_31 ) ;
F_42 ( V_59 ) ;
F_43 ( V_59 ) ;
}
V_12 -> V_71 = V_31 ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_41 << 4 ) | 1 , ( T_1 ) 12 ) ;
return;
}
if ( ! ( V_1 = F_33 ( V_7 -> V_64 , V_45 , & V_43 ) ) ) return;
V_21 = 1 ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) , V_21 ++ )
if ( V_5 -> V_31 ) if ( F_22 ( V_5 ) == V_41 ) goto V_18;
F_20 ( V_7 -> V_64 , L_26 , V_41 , V_45 ) ;
goto V_82;
V_18:
F_12 ( V_7 , F_14 , ( ( T_1 ) V_41 << 4 ) | 1 , ( ( T_1 ) V_45 << 4 ) | V_21 ) ;
if ( ! V_31 ) {
V_5 -> V_31 = 0 ;
F_47 ( & V_5 -> V_32 , - 4 ) ;
F_24 ( & V_1 -> V_33 , - 4 ) ;
memmove ( F_4 ( V_5 ) , ( char * ) F_4 ( V_5 ) + 4 ,
( char * ) V_1 + F_5 ( V_1 -> V_33 ) - ( char * ) F_4 ( V_5 ) ) ;
} else {
struct V_1 * V_84 ;
struct V_42 V_48 ;
* ( T_2 * ) ( ( void * ) V_5 + F_23 ( V_5 -> V_32 ) - 4 ) = V_31 ;
if ( ( V_84 = F_33 ( V_7 -> V_64 , V_31 , & V_48 ) ) ) {
V_84 -> V_45 = F_26 ( V_45 ) ;
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
}
}
} else {
F_20 ( V_7 -> V_64 , L_27 , V_41 , F_5 ( V_1 -> V_33 ) ) ;
goto V_82;
}
if ( ! V_5 -> V_39 ) {
struct V_3 * V_86 = F_4 ( V_5 ) ;
struct V_3 * V_87 ;
struct V_1 * V_84 ;
struct V_42 V_48 ;
if ( ! V_86 -> V_31 ) goto V_88;
V_80 = F_22 ( V_86 ) ;
if ( ! ( V_87 = F_9 ( F_23 ( V_5 -> V_32 ) , V_15 ) ) ) {
F_6 ( L_28 ) ;
goto V_88;
}
memcpy ( V_87 , V_5 , F_23 ( V_5 -> V_32 ) ) ;
F_31 ( V_7 -> V_64 , V_1 , V_5 ) ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_45 << 4 ) | V_21 , 4 ) ;
F_12 ( V_7 , F_16 , ( ( T_1 ) V_45 << 4 ) | V_21 , 1 ) ;
if ( V_87 -> V_31 ) if ( ( V_84 = F_33 ( V_7 -> V_64 , F_22 ( V_87 ) , & V_48 ) ) ) {
V_84 -> V_45 = F_26 ( V_80 ) ;
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
}
F_36 ( V_7 , V_80 , V_87 -> V_35 , V_87 -> V_36 , V_87 , V_87 -> V_31 ? F_22 ( V_87 ) : 0 ) ;
V_41 = V_45 ;
F_10 ( V_87 ) ;
goto V_81;
} else {
struct V_3 * V_89 = F_17 ( V_1 ) ;
struct V_3 * V_87 ;
struct V_1 * V_84 ;
struct V_42 V_48 ;
T_2 V_90 ;
if ( ! V_89 ) {
F_20 ( V_7 -> V_64 , L_29 , V_45 ) ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
V_41 = V_45 ;
goto V_81;
}
if ( ! V_89 -> V_31 ) goto V_88;
V_80 = F_22 ( V_89 ) ;
if ( ( V_84 = F_33 ( V_7 -> V_64 , V_80 , & V_48 ) ) ) {
struct V_3 * V_91 = F_18 ( V_84 ) ;
V_90 = V_91 -> V_31 ? F_22 ( V_91 ) : 0 ;
if ( ! V_90 && V_31 ) {
if ( F_5 ( V_84 -> V_33 ) > 2044 ) {
if ( F_21 ( V_7 -> V_64 ) -> V_30 >= 2 ) {
F_6 ( L_30 ) ;
F_6 ( L_31 ) ;
}
F_35 ( & V_48 ) ;
goto V_88;
}
if ( F_21 ( V_7 -> V_64 ) -> V_30 >= 2 ) {
F_6 ( L_30 ) ;
F_6 ( L_32 ) ;
}
F_47 ( & V_91 -> V_32 , 4 ) ;
V_91 -> V_31 = 1 ;
F_24 ( & V_84 -> V_33 , 4 ) ;
}
if ( V_90 && ! V_31 ) {
F_47 ( & V_91 -> V_32 , - 4 ) ;
V_91 -> V_31 = 0 ;
F_24 ( & V_84 -> V_33 , - 4 ) ;
} else if ( V_31 )
* ( V_34 * ) ( ( void * ) V_91 + F_23 ( V_91 -> V_32 ) - 4 ) = F_26 ( V_31 ) ;
} else goto V_88;
if ( ! ( V_87 = F_9 ( F_23 ( V_89 -> V_32 ) , V_15 ) ) ) {
F_6 ( L_28 ) ;
F_35 ( & V_48 ) ;
goto V_88;
}
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
memcpy ( V_87 , V_89 , F_23 ( V_89 -> V_32 ) ) ;
F_31 ( V_7 -> V_64 , V_1 , V_89 ) ;
if ( ! V_89 -> V_31 ) {
F_47 ( & V_89 -> V_32 , 4 ) ;
V_89 -> V_31 = 1 ;
F_24 ( & V_1 -> V_33 , 4 ) ;
}
* ( V_34 * ) ( ( void * ) V_89 + F_23 ( V_89 -> V_32 ) - 4 ) = F_26 ( V_80 ) ;
F_34 ( & V_43 ) ;
F_35 ( & V_43 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_45 << 4 ) | ( V_21 - 1 ) , 4 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_45 << 4 ) | V_21 , ( ( T_1 ) V_45 << 4 ) | ( V_21 - 1 ) ) ;
if ( V_31 ) if ( ( V_84 = F_33 ( V_7 -> V_64 , F_22 ( V_5 ) , & V_48 ) ) ) {
V_84 -> V_45 = F_26 ( V_80 ) ;
F_34 ( & V_48 ) ;
F_35 ( & V_48 ) ;
}
F_36 ( V_7 , V_80 , V_87 -> V_35 , V_87 -> V_36 , V_87 , V_90 ) ;
V_41 = V_45 ;
F_10 ( V_87 ) ;
goto V_81;
}
V_88:
F_34 ( & V_43 ) ;
V_82:
F_35 ( & V_43 ) ;
}
int F_49 ( struct V_9 * V_7 , T_2 V_41 , struct V_3 * V_5 ,
struct V_42 * V_43 , int V_92 )
{
struct V_1 * V_1 = V_43 -> V_93 ;
T_2 V_31 = 0 ;
T_1 V_22 ;
if ( V_5 -> V_94 || V_5 -> V_39 ) {
F_20 ( V_7 -> V_64 , L_33 , V_41 ) ;
F_35 ( V_43 ) ;
return 1 ;
}
if ( V_5 -> V_31 ) V_31 = F_22 ( V_5 ) ;
if ( V_92 && ( V_5 -> V_31 || ( V_5 == F_3 ( V_1 ) && F_4 ( V_5 ) -> V_39 ) ) ) {
if ( F_45 ( V_7 -> V_64 , V_95 ) ) {
F_35 ( V_43 ) ;
return 2 ;
}
}
V_7 -> V_74 ++ ;
F_12 ( V_7 , F_16 , ( V_22 = F_1 ( V_1 , V_5 ) ) + 1 , 1 ) ;
F_31 ( V_7 -> V_64 , V_1 , V_5 ) ;
F_34 ( V_43 ) ;
F_35 ( V_43 ) ;
if ( V_31 ) {
T_2 V_79 = F_46 ( V_7 , V_31 , V_41 ) ;
F_12 ( V_7 , F_14 , 5 , V_22 ) ;
if ( V_79 ) F_48 ( V_7 , V_79 ) ;
return ! V_79 ;
}
F_48 ( V_7 , V_41 ) ;
return 0 ;
}
void F_50 ( struct V_27 * V_28 , T_2 V_41 , int * V_96 ,
int * V_97 , int * V_98 )
{
struct V_1 * V_1 ;
struct V_42 V_43 ;
struct V_3 * V_5 ;
T_2 V_29 , V_99 = 0 ;
int V_61 , V_62 = 0 ;
int V_84 , V_100 = 0 ;
V_101:
if ( V_96 ) ( * V_96 ) ++ ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_37 ( V_28 , V_41 , & V_61 , & V_62 , L_34 ) ) return;
V_29 = 0 ;
V_63:
if ( ! ( V_1 = F_33 ( V_28 , V_41 , & V_43 ) ) ) return;
if ( F_21 ( V_28 ) -> V_30 ) if ( V_99 && V_99 != - 1 && F_5 ( V_1 -> V_45 ) != V_99 )
F_20 ( V_28 , L_35 , V_99 , V_41 , F_5 ( V_1 -> V_45 ) ) ;
V_5 = F_3 ( V_1 ) ;
if ( V_29 ) while( 1 ) {
if ( V_5 -> V_31 ) if ( F_22 ( V_5 ) == V_29 ) goto V_102;
if ( V_5 -> V_39 ) {
F_35 ( & V_43 ) ;
F_20 ( V_28 , L_36 ,
V_29 , V_41 , V_99 ) ;
return;
}
V_5 = F_4 ( V_5 ) ;
}
V_103:
if ( V_5 -> V_31 ) {
V_99 = V_41 ;
V_41 = F_22 ( V_5 ) ;
F_35 ( & V_43 ) ;
goto V_101;
}
V_102:
if ( ! V_5 -> V_94 && ! V_5 -> V_39 && V_5 -> V_104 && V_97 ) ( * V_97 ) ++ ;
if ( ! V_5 -> V_94 && ! V_5 -> V_39 && V_98 ) ( * V_98 ) ++ ;
if ( ( V_5 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) goto V_103;
V_29 = V_41 ;
V_41 = F_5 ( V_1 -> V_45 ) ;
if ( V_1 -> V_46 ) {
F_35 ( & V_43 ) ;
return;
}
F_35 ( & V_43 ) ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_37 ( V_28 , V_29 , & V_84 , & V_100 , L_37 ) ) return;
V_99 = - 1 ;
goto V_63;
}
static struct V_3 * F_51 ( struct V_27 * V_28 , T_2 V_41 , int V_24 ,
struct V_42 * V_43 , struct V_1 * * V_105 )
{
int V_7 ;
struct V_3 * V_5 , * V_6 ;
struct V_1 * V_1 ;
V_1 = F_33 ( V_28 , V_41 , V_43 ) ;
if ( ! V_1 ) return NULL ;
if ( V_105 ) * V_105 = V_1 ;
V_5 = F_3 ( V_1 ) ;
V_6 = F_2 ( V_1 ) ;
for ( V_7 = 1 ; V_5 < V_6 ; V_7 ++ , V_5 = F_4 ( V_5 ) ) {
if ( V_7 == V_24 ) {
return V_5 ;
}
if ( V_5 -> V_39 ) break;
}
F_35 ( V_43 ) ;
F_20 ( V_28 , L_38 , V_41 , V_24 ) ;
return NULL ;
}
T_2 F_52 ( struct V_27 * V_28 , T_2 V_41 )
{
struct V_42 V_43 ;
T_2 V_2 = V_41 ;
T_2 V_45 = 0 ;
struct V_3 * V_5 ;
int V_61 , V_62 = 0 ;
V_106:
if ( F_21 ( V_28 ) -> V_30 )
if ( F_37 ( V_28 , V_2 , & V_61 , & V_62 , L_39 ) )
return V_2 ;
if ( ! ( V_5 = F_51 ( V_28 , V_2 , 1 , & V_43 , NULL ) ) ) return V_41 ;
if ( F_21 ( V_28 ) -> V_30 )
if ( V_45 && F_5 ( ( (struct V_1 * ) V_43 . V_93 ) -> V_45 ) != V_45 )
F_20 ( V_28 , L_40 , V_45 , V_2 , F_5 ( ( (struct V_1 * ) V_43 . V_93 ) -> V_45 ) ) ;
if ( ! V_5 -> V_31 ) {
F_35 ( & V_43 ) ;
return V_2 ;
}
V_45 = V_2 ;
V_2 = F_22 ( V_5 ) ;
F_35 ( & V_43 ) ;
goto V_106;
}
struct V_3 * F_53 ( struct V_9 * V_9 , T_1 * V_107 ,
struct V_42 * V_43 )
{
T_1 V_10 ;
unsigned V_23 ;
T_2 V_41 ;
struct V_3 * V_5 , * V_2 ;
struct V_3 * V_108 ;
struct V_3 * V_109 ;
struct V_1 * V_1 ;
struct V_1 * V_110 ;
struct V_42 V_111 ;
V_10 = * V_107 ;
V_41 = V_10 >> 6 << 2 ;
V_10 &= 077 ;
if ( ! ( V_5 = F_51 ( V_9 -> V_64 , V_41 , V_10 , V_43 , & V_1 ) ) )
goto V_112;
if ( ( V_2 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) {
if ( ! ( ++ * V_107 & 077 ) ) {
F_20 ( V_9 -> V_64 ,
L_41 ,
( unsigned long long ) * V_107 ) ;
goto V_112;
}
if ( V_2 -> V_31 ) {
* V_107 = ( ( T_1 ) F_52 ( V_9 -> V_64 , F_22 ( V_2 ) ) << 4 ) + 1 ;
}
return V_5 ;
}
if ( V_1 -> V_46 ) goto V_112;
if ( ! ( V_110 = F_33 ( V_9 -> V_64 , F_5 ( V_1 -> V_45 ) , & V_111 ) ) )
goto V_112;
V_109 = F_2 ( V_110 ) ;
V_23 = 0 ;
for ( V_108 = F_3 ( V_110 ) ; V_108 < V_109 ;
V_108 = F_4 ( V_108 ) ) {
if ( ! ( ++ V_23 & 077 ) ) F_20 ( V_9 -> V_64 ,
L_42 , F_5 ( V_1 -> V_45 ) ) ;
if ( V_108 -> V_31 && F_22 ( V_108 ) == V_41 ) {
* V_107 = ( ( T_1 ) F_5 ( V_1 -> V_45 ) << 4 ) + V_23 ;
F_35 ( & V_111 ) ;
return V_5 ;
}
}
F_20 ( V_9 -> V_64 , L_43 ,
V_41 , F_5 ( V_1 -> V_45 ) ) ;
F_35 ( & V_111 ) ;
V_112:
* V_107 = 12 ;
return V_5 ;
}
struct V_3 * F_54 ( struct V_9 * V_9 , T_2 V_41 ,
const unsigned char * V_35 , unsigned V_113 ,
T_2 * V_44 , struct V_42 * V_43 )
{
struct V_1 * V_1 ;
struct V_3 * V_5 ;
struct V_3 * V_6 ;
int V_61 , V_62 = 0 ;
if ( ! F_55 ( V_9 -> V_114 ) ) F_20 ( V_9 -> V_64 , L_44 ) ;
V_106:
if ( F_21 ( V_9 -> V_64 ) -> V_30 )
if ( F_37 ( V_9 -> V_64 , V_41 , & V_61 , & V_62 , L_45 ) ) return NULL ;
if ( ! ( V_1 = F_33 ( V_9 -> V_64 , V_41 , V_43 ) ) ) return NULL ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_22 = F_29 ( V_9 -> V_64 , V_35 , V_113 , V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_39 ) ;
if ( ! V_22 ) {
if ( V_44 ) * V_44 = V_41 ;
return V_5 ;
}
if ( V_22 < 0 ) {
if ( V_5 -> V_31 ) {
V_41 = F_22 ( V_5 ) ;
F_35 ( V_43 ) ;
goto V_106;
}
break;
}
}
F_35 ( V_43 ) ;
return NULL ;
}
void F_56 ( struct V_27 * V_28 , T_2 V_41 )
{
struct V_42 V_43 ;
struct V_1 * V_1 ;
struct V_3 * V_5 ;
T_2 V_84 , V_100 , V_54 = V_41 ;
while ( 1 ) {
if ( ! ( V_1 = F_33 ( V_28 , V_41 , & V_43 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( V_5 -> V_39 ) {
if ( V_5 -> V_31 ) V_84 = F_22 ( V_5 ) ;
else goto error;
F_35 ( & V_43 ) ;
F_41 ( V_28 , V_41 ) ;
V_41 = V_84 ;
} else break;
}
if ( ! V_5 -> V_94 ) goto error;
V_84 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
V_5 = F_4 ( V_5 ) ;
if ( ! V_5 -> V_39 ) goto error;
V_100 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
F_35 ( & V_43 ) ;
F_41 ( V_28 , V_41 ) ;
do {
while ( V_84 ) {
if ( ! ( V_1 = F_33 ( V_28 , V_41 = V_84 , & V_43 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( ! V_5 -> V_39 ) goto error;
V_84 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
F_35 ( & V_43 ) ;
F_41 ( V_28 , V_41 ) ;
}
V_84 = V_100 ;
V_100 = 0 ;
} while ( V_84 );
return;
error:
F_35 ( & V_43 ) ;
F_41 ( V_28 , V_41 ) ;
F_20 ( V_28 , L_46 , V_54 ) ;
}
struct V_3 * F_57 ( struct V_27 * V_28 , T_4 V_115 ,
struct V_60 * F_13 , struct V_42 * V_43 )
{
unsigned char * V_116 ;
unsigned char * V_117 ;
int V_118 , V_119 ;
struct V_1 * V_2 ;
T_2 V_41 , V_120 ;
struct V_60 * V_121 ;
struct V_58 * V_59 ;
struct V_3 * V_5 , * V_6 ;
int V_23 ;
int V_61 , V_62 = 0 ;
int V_84 , V_100 = 0 ;
V_116 = F_13 -> V_35 ;
if ( ! ( V_117 = F_9 ( 256 , V_15 ) ) ) {
F_6 ( L_47 ) ;
return NULL ;
}
if ( F_13 -> V_113 <= 15 )
memcpy ( V_117 , V_116 , V_118 = V_119 = F_13 -> V_113 ) ;
else {
memcpy ( V_117 , V_116 , 15 ) ;
memset ( V_117 + 15 , 0xff , 256 - 15 ) ;
V_118 = 15 ; V_119 = 256 ;
}
if ( ! ( V_121 = F_40 ( V_28 , F_5 ( F_13 -> V_45 ) , & V_59 ) ) ) {
F_10 ( V_117 ) ;
return NULL ;
}
if ( ! F_58 ( V_121 ) ) {
F_43 ( V_59 ) ;
F_20 ( V_28 , L_48 , V_115 , F_5 ( F_13 -> V_45 ) ) ;
F_10 ( V_117 ) ;
return NULL ;
}
V_41 = F_5 ( V_121 -> V_68 . V_69 [ 0 ] . V_70 ) ;
F_43 ( V_59 ) ;
V_101:
V_120 = 0 ;
V_63:
if ( ! ( V_2 = F_33 ( V_28 , V_41 , V_43 ) ) ) {
F_10 ( V_117 ) ;
return NULL ;
}
V_6 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_2 ) ;
if ( V_120 ) {
while ( V_5 < V_6 ) {
if ( V_5 -> V_31 ) if ( F_22 ( V_5 ) == V_120 ) goto F_13;
V_5 = F_4 ( V_5 ) ;
}
F_20 ( V_28 , L_49 , V_120 , V_41 ) ;
F_35 ( V_43 ) ;
F_10 ( V_117 ) ;
return NULL ;
}
V_103:
if ( F_5 ( V_5 -> V_60 ) == V_115 ) {
F_10 ( V_117 ) ;
return V_5 ;
}
V_23 = F_29 ( V_28 , V_116 , V_118 , V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_39 ) ;
if ( V_23 < 0 && V_5 -> V_31 ) {
V_41 = F_22 ( V_5 ) ;
F_35 ( V_43 ) ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_37 ( V_28 , V_41 , & V_61 , & V_62 , L_50 ) ) {
F_10 ( V_117 ) ;
return NULL ;
}
goto V_101;
}
F_13:
if ( F_5 ( V_5 -> V_60 ) == V_115 ) {
F_10 ( V_117 ) ;
return V_5 ;
}
V_23 = F_29 ( V_28 , V_117 , V_119 , V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_39 ) ;
if ( V_23 < 0 && ! V_5 -> V_39 ) goto V_122;
if ( ( V_5 = F_4 ( V_5 ) ) < V_6 ) goto V_103;
if ( V_2 -> V_46 ) goto V_122;
V_120 = V_41 ;
V_41 = F_5 ( V_2 -> V_45 ) ;
F_35 ( V_43 ) ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_37 ( V_28 , V_120 , & V_84 , & V_100 , L_51 ) ) {
F_10 ( V_117 ) ;
return NULL ;
}
goto V_63;
V_122:
F_35 ( V_43 ) ;
F_20 ( V_28 , L_52 , V_115 ) ;
F_10 ( V_117 ) ;
return NULL ;
}
