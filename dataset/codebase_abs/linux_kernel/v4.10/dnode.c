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
int F_7 ( struct V_10 * V_10 , T_1 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_7 = 0 ;
T_1 * * V_14 ;
if ( V_13 -> V_15 )
for (; V_13 -> V_15 [ V_7 ] ; V_7 ++ )
if ( V_13 -> V_15 [ V_7 ] == V_11 )
return 0 ;
if ( ! ( V_7 & 0x0f ) ) {
if ( ! ( V_14 = F_9 ( ( V_7 + 0x11 ) * sizeof( T_1 * ) , V_16 ) ) ) {
F_10 ( L_2 ) ;
return - V_17 ;
}
if ( V_13 -> V_15 ) {
memcpy ( V_14 , V_13 -> V_15 , V_7 * sizeof( T_1 ) ) ;
F_11 ( V_13 -> V_15 ) ;
}
V_13 -> V_15 = V_14 ;
}
V_13 -> V_15 [ V_7 ] = V_11 ;
V_13 -> V_15 [ V_7 + 1 ] = NULL ;
return 0 ;
}
void F_12 ( struct V_10 * V_10 , T_1 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
T_1 * * V_7 , * * V_18 ;
if ( ! V_13 -> V_15 ) goto V_19;
for ( V_7 = V_13 -> V_15 ; * V_7 ; V_7 ++ ) if ( * V_7 == V_11 ) goto V_20;
goto V_19;
V_20:
for ( V_18 = V_7 + 1 ; * V_18 ; V_18 ++ ) ;
* V_7 = * ( V_18 - 1 ) ;
* ( V_18 - 1 ) = NULL ;
if ( V_18 - 1 == V_13 -> V_15 ) {
F_11 ( V_13 -> V_15 ) ;
V_13 -> V_15 = NULL ;
}
return;
V_19:
return;
}
static void F_13 ( struct V_10 * V_10 , void (* F_14)( T_1 * , T_1 , T_1 ) ,
T_1 V_21 , T_1 V_22 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
T_1 * * V_7 ;
if ( ! V_13 -> V_15 ) return;
for ( V_7 = V_13 -> V_15 ; * V_7 ; V_7 ++ ) (* F_14)( * V_7 , V_21 , V_22 ) ;
return;
}
static void F_15 ( T_1 * V_23 , T_1 F_14 , T_1 V_24 )
{
if ( * V_23 == F_14 ) * V_23 = V_24 ;
}
static void F_16 ( T_1 * V_23 , T_1 V_2 , T_1 V_25 )
{
if ( ( * V_23 & ~ 0x3f ) == ( V_2 & ~ 0x3f ) && ( * V_23 & 0x3f ) >= ( V_2 & 0x3f ) ) {
int V_26 = ( * V_23 & 0x3f ) + V_25 ;
if ( V_26 > 0x3f )
F_10 ( L_3 ,
V_9 , ( int ) * V_23 , ( int ) V_25 >> 8 ) ;
else
* V_23 = ( * V_23 & ~ 0x3f ) | V_26 ;
}
}
static void F_17 ( T_1 * V_23 , T_1 V_2 , T_1 V_25 )
{
if ( ( * V_23 & ~ 0x3f ) == ( V_2 & ~ 0x3f ) && ( * V_23 & 0x3f ) >= ( V_2 & 0x3f ) ) {
int V_26 = ( * V_23 & 0x3f ) - V_25 ;
if ( V_26 < 1 )
F_10 ( L_4 ,
V_9 , ( int ) * V_23 , ( int ) V_25 >> 8 ) ;
else
* V_23 = ( * V_23 & ~ 0x3f ) | V_26 ;
}
}
static struct V_3 * F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_5 , * V_6 , * V_27 = NULL , * V_28 = NULL ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
V_28 = V_27 ; V_27 = V_5 ;
}
return V_28 ;
}
static struct V_3 * F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_5 , * V_6 , * V_27 = NULL ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
V_27 = V_5 ;
}
return V_27 ;
}
static void F_20 ( struct V_29 * V_30 , struct V_1 * V_2 , T_2 V_31 )
{
struct V_3 * V_5 ;
if ( ! ( V_5 = F_19 ( V_2 ) ) ) {
F_21 ( V_30 , L_5 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
if ( F_22 ( V_30 ) -> V_32 ) {
if ( V_5 -> V_33 ) {
F_21 ( V_30 , L_6 ,
F_5 ( V_2 -> V_8 ) , F_23 ( V_5 ) ) ;
return;
}
if ( F_24 ( V_5 -> V_34 ) != 32 ) {
F_21 ( V_30 , L_7 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
}
if ( V_31 ) {
F_25 ( & V_2 -> V_35 , 4 ) ;
if ( F_5 ( V_2 -> V_35 ) > 2048 ) {
F_21 ( V_30 , L_8 , F_5 ( V_2 -> V_8 ) ) ;
F_25 ( & V_2 -> V_35 , - 4 ) ;
return;
}
V_5 -> V_34 = F_26 ( 36 ) ;
V_5 -> V_33 = 1 ;
* ( V_36 * ) ( ( char * ) V_5 + 32 ) = F_27 ( V_31 ) ;
}
}
struct V_3 * F_28 ( struct V_29 * V_30 , struct V_1 * V_2 ,
const unsigned char * V_37 ,
unsigned V_38 , T_3 V_39 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
unsigned V_40 = F_29 ( V_38 , V_39 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_25 = F_30 ( V_30 , V_37 , V_38 , V_5 -> V_37 , V_5 -> V_38 , V_5 -> V_41 ) ;
if ( ! V_25 ) {
F_21 ( V_30 , L_9 , * V_37 , V_38 , F_5 ( V_2 -> V_8 ) ) ;
return NULL ;
}
if ( V_25 < 0 ) break;
}
memmove ( ( char * ) V_5 + V_40 , V_5 , ( char * ) V_6 - ( char * ) V_5 ) ;
memset ( V_5 , 0 , V_40 ) ;
if ( V_39 ) {
* ( V_36 * ) ( ( char * ) V_5 + V_40 - 4 ) = F_27 ( V_39 ) ;
V_5 -> V_33 = 1 ;
}
V_5 -> V_34 = F_26 ( V_40 ) ;
V_5 -> V_42 = F_31 ( V_37 , V_38 ) ;
V_5 -> V_38 = V_38 ;
memcpy ( V_5 -> V_37 , V_37 , V_38 ) ;
F_25 ( & V_2 -> V_35 , V_40 ) ;
return V_5 ;
}
static void F_32 ( struct V_29 * V_30 , struct V_1 * V_2 ,
struct V_3 * V_5 )
{
if ( V_5 -> V_41 ) {
F_21 ( V_30 , L_10 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
V_2 -> V_35 = F_27 ( F_5 ( V_2 -> V_35 ) - F_24 ( V_5 -> V_34 ) ) ;
memmove ( V_5 , F_4 ( V_5 ) , F_5 ( V_2 -> V_35 ) + ( char * ) V_2 - ( char * ) V_5 ) ;
}
static void F_33 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
T_2 V_43 = F_5 ( V_2 -> V_8 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) )
if ( V_5 -> V_33 ) {
struct V_44 V_45 ;
struct V_1 * V_46 ;
if ( ( V_46 = F_34 ( V_30 , F_23 ( V_5 ) , & V_45 ) ) ) {
if ( F_5 ( V_46 -> V_47 ) != V_43 || V_46 -> V_48 ) {
V_46 -> V_47 = F_27 ( V_43 ) ;
V_46 -> V_48 = 0 ;
F_35 ( & V_45 ) ;
}
F_36 ( & V_45 ) ;
}
}
}
static int F_37 ( struct V_10 * V_7 , T_2 V_43 ,
const unsigned char * V_37 , unsigned V_38 ,
struct V_3 * V_49 , T_2 V_39 )
{
struct V_44 V_45 , V_50 , V_51 ;
struct V_1 * V_2 , * V_52 , * V_53 , * V_54 = NULL ;
T_2 V_55 , V_56 ;
struct V_3 * V_5 ;
struct V_3 V_57 ;
unsigned char * V_58 ;
int V_59 ;
int V_11 ;
struct V_60 * V_61 ;
struct V_62 * V_62 ;
int V_63 , V_64 = 0 ;
if ( ! ( V_58 = F_9 ( 256 , V_16 ) ) ) {
F_10 ( L_11 ) ;
return 1 ;
}
V_65:
if ( V_38 >= 256 ) {
F_21 ( V_7 -> V_66 , L_12 , V_9 , V_38 ) ;
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
if ( ! ( V_2 = F_34 ( V_7 -> V_66 , V_43 , & V_45 ) ) ) {
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
V_67:
if ( F_22 ( V_7 -> V_66 ) -> V_32 )
if ( F_38 ( V_7 -> V_66 , V_43 , & V_63 , & V_64 , L_13 ) ) {
F_36 ( & V_45 ) ;
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
if ( F_5 ( V_2 -> V_35 ) + F_29 ( V_38 , V_39 ) <= 2048 ) {
T_1 V_24 ;
F_39 ( V_5 = F_28 ( V_7 -> V_66 , V_2 , V_37 , V_38 , V_39 ) , V_49 ) ;
V_24 = F_1 ( V_2 , V_5 ) ;
F_13 ( V_7 , F_16 , V_24 , 1 ) ;
F_13 ( V_7 , F_15 , 4 , V_24 ) ;
F_13 ( V_7 , F_15 , 5 , V_24 + 1 ) ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 0 ;
}
if ( ! V_54 ) if ( ! ( V_54 = F_9 ( 0x924 , V_16 ) ) ) {
F_10 ( L_14 ) ;
F_36 ( & V_45 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
memcpy ( V_54 , V_2 , F_5 ( V_2 -> V_35 ) ) ;
F_39 ( V_5 = F_28 ( V_7 -> V_66 , V_54 , V_37 , V_38 , V_39 ) , V_49 ) ;
F_13 ( V_7 , F_16 , F_1 ( V_54 , V_5 ) , 1 ) ;
V_59 = ( ( char * ) F_19 ( V_54 ) - ( char * ) V_54 ) / 2 + 10 ;
if ( ! ( V_52 = F_40 ( V_7 -> V_66 , F_5 ( V_2 -> V_47 ) , & V_55 , & V_50 ) ) ) {
F_21 ( V_7 -> V_66 , L_15 ) ;
F_36 ( & V_45 ) ;
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
V_7 -> V_68 += 2048 ;
V_7 -> V_69 += 4 ;
V_11 = 1 ;
for ( V_5 = F_3 ( V_54 ) ; ( char * ) F_4 ( V_5 ) - ( char * ) V_54 < V_59 ; V_5 = F_4 ( V_5 ) ) {
F_39 ( F_28 ( V_7 -> V_66 , V_52 , V_5 -> V_37 , V_5 -> V_38 , V_5 -> V_33 ? F_23 ( V_5 ) : 0 ) , V_5 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_43 << 4 ) | V_11 , ( ( T_1 ) V_55 << 4 ) | V_11 ) ;
V_11 ++ ;
}
F_39 ( V_49 = & V_57 , V_5 ) ;
memcpy ( V_58 , V_5 -> V_37 , V_5 -> V_38 ) ;
V_37 = V_58 ;
V_38 = V_5 -> V_38 ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_43 << 4 ) | V_11 , 4 ) ;
V_39 = V_55 ;
F_20 ( V_7 -> V_66 , V_52 , V_5 -> V_33 ? F_23 ( V_5 ) : 0 ) ;
V_5 = F_4 ( V_5 ) ;
memmove ( ( char * ) V_54 + 20 , V_5 , F_5 ( V_54 -> V_35 ) + ( char * ) V_54 - ( char * ) V_5 ) ;
F_25 ( & V_54 -> V_35 , - ( ( char * ) V_5 - ( char * ) V_54 - 20 ) ) ;
memcpy ( V_2 , V_54 , F_5 ( V_54 -> V_35 ) ) ;
F_13 ( V_7 , F_17 , ( T_1 ) V_43 << 4 , V_11 ) ;
F_33 ( V_7 -> V_66 , V_52 ) ;
if ( ! V_2 -> V_48 ) {
V_52 -> V_47 = V_2 -> V_47 ;
V_43 = F_5 ( V_52 -> V_47 ) ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
goto V_65;
}
if ( ! ( V_53 = F_40 ( V_7 -> V_66 , F_5 ( V_2 -> V_47 ) , & V_56 , & V_51 ) ) ) {
F_21 ( V_7 -> V_66 , L_15 ) ;
F_36 ( & V_45 ) ;
F_36 ( & V_50 ) ;
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
V_7 -> V_68 += 2048 ;
V_7 -> V_69 += 4 ;
V_53 -> V_48 = 1 ;
V_53 -> V_47 = V_2 -> V_47 ;
if ( ! ( V_62 = F_41 ( V_7 -> V_66 , F_5 ( V_2 -> V_47 ) , & V_61 ) ) ) {
F_42 ( V_7 -> V_66 , V_56 ) ;
F_36 ( & V_45 ) ;
F_36 ( & V_50 ) ;
F_36 ( & V_51 ) ;
F_11 ( V_54 ) ;
F_11 ( V_58 ) ;
return 1 ;
}
V_62 -> V_70 . V_71 [ 0 ] . V_72 = F_27 ( V_56 ) ;
F_43 ( V_61 ) ;
F_44 ( V_61 ) ;
F_8 ( V_7 ) -> V_73 = V_56 ;
V_2 -> V_47 = V_52 -> V_47 = F_27 ( V_56 ) ;
V_2 -> V_48 = V_52 -> V_48 = 0 ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
V_45 = V_51 ;
F_20 ( V_7 -> V_66 , V_53 , V_43 ) ;
V_43 = V_56 ;
V_2 = V_53 ;
goto V_67;
}
int F_45 ( struct V_10 * V_7 ,
const unsigned char * V_37 , unsigned V_38 ,
struct V_3 * V_49 )
{
struct V_12 * V_13 = F_8 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_3 * V_5 , * V_6 ;
struct V_44 V_45 ;
T_2 V_43 ;
int V_25 ;
int V_63 , V_64 = 0 ;
V_43 = V_13 -> V_73 ;
V_33:
if ( F_22 ( V_7 -> V_66 ) -> V_32 )
if ( F_38 ( V_7 -> V_66 , V_43 , & V_63 , & V_64 , L_16 ) ) return 1 ;
if ( ! ( V_2 = F_34 ( V_7 -> V_66 , V_43 , & V_45 ) ) ) return 1 ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
if ( ! ( V_25 = F_30 ( V_7 -> V_66 , V_37 , V_38 , V_5 -> V_37 , V_5 -> V_38 , V_5 -> V_41 ) ) ) {
F_36 ( & V_45 ) ;
return - 1 ;
}
if ( V_25 < 0 ) {
if ( V_5 -> V_33 ) {
V_43 = F_23 ( V_5 ) ;
F_36 ( & V_45 ) ;
goto V_33;
}
break;
}
}
F_36 ( & V_45 ) ;
if ( F_46 ( V_7 -> V_66 , V_74 ) ) {
V_25 = 1 ;
goto V_75;
}
V_7 -> V_76 ++ ;
V_25 = F_37 ( V_7 , V_43 , V_37 , V_38 , V_49 , 0 ) ;
V_75:
return V_25 ;
}
static T_3 F_47 ( struct V_10 * V_7 , T_2 V_77 , T_2 V_78 )
{
T_2 V_43 , V_79 ;
T_2 V_80 = V_78 ;
struct V_1 * V_1 ;
struct V_44 V_45 ;
struct V_3 * V_5 , * V_57 ;
int V_81 ;
T_1 V_24 ;
int V_63 , V_64 = 0 ;
V_43 = V_77 ;
while ( 1 ) {
if ( F_22 ( V_7 -> V_66 ) -> V_32 )
if ( F_38 ( V_7 -> V_66 , V_43 , & V_63 , & V_64 , L_17 ) )
return 0 ;
if ( ! ( V_1 = F_34 ( V_7 -> V_66 , V_43 , & V_45 ) ) ) return 0 ;
if ( F_22 ( V_7 -> V_66 ) -> V_32 ) {
if ( F_5 ( V_1 -> V_47 ) != V_80 ) {
F_21 ( V_7 -> V_66 , L_18 ,
V_43 , V_80 , F_5 ( V_1 -> V_47 ) ) ;
F_36 ( & V_45 ) ;
return 0 ;
}
V_80 = V_43 ;
}
if ( ! ( V_5 = F_19 ( V_1 ) ) ) {
F_21 ( V_7 -> V_66 , L_19 , V_43 ) ;
F_36 ( & V_45 ) ;
return 0 ;
}
if ( ! V_5 -> V_33 ) break;
V_43 = F_23 ( V_5 ) ;
F_36 ( & V_45 ) ;
}
while ( ! ( V_5 = F_18 ( V_1 ) ) ) {
T_2 V_47 = F_5 ( V_1 -> V_47 ) ;
F_36 ( & V_45 ) ;
F_42 ( V_7 -> V_66 , V_43 ) ;
V_7 -> V_68 -= 2048 ;
V_7 -> V_69 -= 4 ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_43 << 4 ) | 1 , 5 ) ;
if ( V_47 == V_78 ) return V_78 ;
if ( ! ( V_1 = F_34 ( V_7 -> V_66 , V_47 , & V_45 ) ) ) return 0 ;
if ( V_1 -> V_48 ) {
F_21 ( V_7 -> V_66 , L_20 , V_77 , V_78 ) ;
F_36 ( & V_45 ) ;
return 0 ;
}
V_5 = F_19 ( V_1 ) ;
if ( ! V_5 || ! V_5 -> V_33 ) {
F_21 ( V_7 -> V_66 , L_21 , V_47 , V_43 ) ;
F_36 ( & V_45 ) ;
return 0 ;
}
F_25 ( & V_1 -> V_35 , - 4 ) ;
F_48 ( & V_5 -> V_34 , - 4 ) ;
V_5 -> V_33 = 0 ;
F_35 ( & V_45 ) ;
V_43 = V_47 ;
}
V_24 = F_1 ( V_1 , V_5 ) ;
F_13 ( V_7 , F_15 , V_24 , 4 ) ;
F_13 ( V_7 , F_15 , V_24 + 1 , 5 ) ;
if ( ! ( V_57 = F_9 ( F_24 ( V_5 -> V_34 ) , V_16 ) ) ) {
F_21 ( V_7 -> V_66 , L_22 ) ;
F_36 ( & V_45 ) ;
return 0 ;
}
memcpy ( V_57 , V_5 , F_24 ( V_5 -> V_34 ) ) ;
V_79 = V_5 -> V_33 ? F_23 ( V_5 ) : 0 ;
F_32 ( V_7 -> V_66 , V_1 , V_5 ) ;
F_20 ( V_7 -> V_66 , V_1 , V_79 ) ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
V_81 = F_37 ( V_7 , V_78 , V_57 -> V_37 , V_57 -> V_38 , V_57 , V_77 ) ;
F_11 ( V_57 ) ;
if ( V_81 ) return 0 ;
return V_43 ;
}
static void F_49 ( struct V_10 * V_7 , T_2 V_43 )
{
struct V_12 * V_13 = F_8 ( V_7 ) ;
struct V_44 V_45 ;
struct V_1 * V_1 ;
T_2 V_33 , V_47 , V_82 ;
int V_23 ;
struct V_3 * V_5 ;
int V_63 , V_64 = 0 ;
V_83:
if ( F_38 ( V_7 -> V_66 , V_43 , & V_63 , & V_64 , L_23 ) ) return;
if ( ! ( V_1 = F_34 ( V_7 -> V_66 , V_43 , & V_45 ) ) ) return;
if ( F_5 ( V_1 -> V_35 ) > 56 ) goto V_84;
if ( F_5 ( V_1 -> V_35 ) == 52 || F_5 ( V_1 -> V_35 ) == 56 ) {
struct V_3 * V_6 ;
int V_85 = V_1 -> V_48 ;
V_47 = F_5 ( V_1 -> V_47 ) ;
V_5 = F_3 ( V_1 ) ;
V_33 = V_5 -> V_33 ? F_23 ( V_5 ) : 0 ;
if ( F_22 ( V_7 -> V_66 ) -> V_32 ) if ( V_85 && ! V_33 ) {
F_21 ( V_7 -> V_66 , L_24 , V_43 ) ;
goto V_84;
}
F_36 ( & V_45 ) ;
F_42 ( V_7 -> V_66 , V_43 ) ;
V_7 -> V_68 -= 2048 ;
V_7 -> V_69 -= 4 ;
if ( V_85 ) {
struct V_62 * V_62 ;
struct V_60 * V_61 ;
struct V_1 * V_86 ;
struct V_44 V_50 ;
if ( F_22 ( V_7 -> V_66 ) -> V_32 )
if ( V_47 != V_7 -> V_87 ) {
F_21 ( V_7 -> V_66 ,
L_25 ,
V_43 , V_47 ,
( unsigned long ) V_7 -> V_87 ) ;
return;
}
if ( ( V_86 = F_34 ( V_7 -> V_66 , V_33 , & V_50 ) ) ) {
V_86 -> V_47 = F_27 ( V_47 ) ;
V_86 -> V_48 = 1 ;
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
}
if ( ( V_62 = F_41 ( V_7 -> V_66 , V_47 , & V_61 ) ) ) {
V_62 -> V_70 . V_71 [ 0 ] . V_72 = F_27 ( V_33 ) ;
F_43 ( V_61 ) ;
F_44 ( V_61 ) ;
}
V_13 -> V_73 = V_33 ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_43 << 4 ) | 1 , ( T_1 ) 12 ) ;
return;
}
if ( ! ( V_1 = F_34 ( V_7 -> V_66 , V_47 , & V_45 ) ) ) return;
V_23 = 1 ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) , V_23 ++ )
if ( V_5 -> V_33 ) if ( F_23 ( V_5 ) == V_43 ) goto V_20;
F_21 ( V_7 -> V_66 , L_26 , V_43 , V_47 ) ;
goto V_84;
V_20:
F_13 ( V_7 , F_15 , ( ( T_1 ) V_43 << 4 ) | 1 , ( ( T_1 ) V_47 << 4 ) | V_23 ) ;
if ( ! V_33 ) {
V_5 -> V_33 = 0 ;
F_48 ( & V_5 -> V_34 , - 4 ) ;
F_25 ( & V_1 -> V_35 , - 4 ) ;
memmove ( F_4 ( V_5 ) , ( char * ) F_4 ( V_5 ) + 4 ,
( char * ) V_1 + F_5 ( V_1 -> V_35 ) - ( char * ) F_4 ( V_5 ) ) ;
} else {
struct V_1 * V_86 ;
struct V_44 V_50 ;
* ( T_2 * ) ( ( void * ) V_5 + F_24 ( V_5 -> V_34 ) - 4 ) = V_33 ;
if ( ( V_86 = F_34 ( V_7 -> V_66 , V_33 , & V_50 ) ) ) {
V_86 -> V_47 = F_27 ( V_47 ) ;
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
}
}
} else {
F_21 ( V_7 -> V_66 , L_27 , V_43 , F_5 ( V_1 -> V_35 ) ) ;
goto V_84;
}
if ( ! V_5 -> V_41 ) {
struct V_3 * V_88 = F_4 ( V_5 ) ;
struct V_3 * V_89 ;
struct V_1 * V_86 ;
struct V_44 V_50 ;
if ( ! V_88 -> V_33 ) goto V_90;
V_82 = F_23 ( V_88 ) ;
if ( ! ( V_89 = F_9 ( F_24 ( V_5 -> V_34 ) , V_16 ) ) ) {
F_10 ( L_28 ) ;
goto V_90;
}
memcpy ( V_89 , V_5 , F_24 ( V_5 -> V_34 ) ) ;
F_32 ( V_7 -> V_66 , V_1 , V_5 ) ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_47 << 4 ) | V_23 , 4 ) ;
F_13 ( V_7 , F_17 , ( ( T_1 ) V_47 << 4 ) | V_23 , 1 ) ;
if ( V_89 -> V_33 ) if ( ( V_86 = F_34 ( V_7 -> V_66 , F_23 ( V_89 ) , & V_50 ) ) ) {
V_86 -> V_47 = F_27 ( V_82 ) ;
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
}
F_37 ( V_7 , V_82 , V_89 -> V_37 , V_89 -> V_38 , V_89 , V_89 -> V_33 ? F_23 ( V_89 ) : 0 ) ;
V_43 = V_47 ;
F_11 ( V_89 ) ;
goto V_83;
} else {
struct V_3 * V_91 = F_18 ( V_1 ) ;
struct V_3 * V_89 ;
struct V_1 * V_86 ;
struct V_44 V_50 ;
T_2 V_92 ;
if ( ! V_91 ) {
F_21 ( V_7 -> V_66 , L_29 , V_47 ) ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
V_43 = V_47 ;
goto V_83;
}
if ( ! V_91 -> V_33 ) goto V_90;
V_82 = F_23 ( V_91 ) ;
if ( ( V_86 = F_34 ( V_7 -> V_66 , V_82 , & V_50 ) ) ) {
struct V_3 * V_93 = F_19 ( V_86 ) ;
V_92 = V_93 -> V_33 ? F_23 ( V_93 ) : 0 ;
if ( ! V_92 && V_33 ) {
if ( F_5 ( V_86 -> V_35 ) > 2044 ) {
if ( F_22 ( V_7 -> V_66 ) -> V_32 >= 2 ) {
F_10 ( L_30 ) ;
F_10 ( L_31 ) ;
}
F_36 ( & V_50 ) ;
goto V_90;
}
if ( F_22 ( V_7 -> V_66 ) -> V_32 >= 2 ) {
F_10 ( L_30 ) ;
F_10 ( L_32 ) ;
}
F_48 ( & V_93 -> V_34 , 4 ) ;
V_93 -> V_33 = 1 ;
F_25 ( & V_86 -> V_35 , 4 ) ;
}
if ( V_92 && ! V_33 ) {
F_48 ( & V_93 -> V_34 , - 4 ) ;
V_93 -> V_33 = 0 ;
F_25 ( & V_86 -> V_35 , - 4 ) ;
} else if ( V_33 )
* ( V_36 * ) ( ( void * ) V_93 + F_24 ( V_93 -> V_34 ) - 4 ) = F_27 ( V_33 ) ;
} else goto V_90;
if ( ! ( V_89 = F_9 ( F_24 ( V_91 -> V_34 ) , V_16 ) ) ) {
F_10 ( L_28 ) ;
F_36 ( & V_50 ) ;
goto V_90;
}
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
memcpy ( V_89 , V_91 , F_24 ( V_91 -> V_34 ) ) ;
F_32 ( V_7 -> V_66 , V_1 , V_91 ) ;
if ( ! V_91 -> V_33 ) {
F_48 ( & V_91 -> V_34 , 4 ) ;
V_91 -> V_33 = 1 ;
F_25 ( & V_1 -> V_35 , 4 ) ;
}
* ( V_36 * ) ( ( void * ) V_91 + F_24 ( V_91 -> V_34 ) - 4 ) = F_27 ( V_82 ) ;
F_35 ( & V_45 ) ;
F_36 ( & V_45 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_47 << 4 ) | ( V_23 - 1 ) , 4 ) ;
F_13 ( V_7 , F_15 , ( ( T_1 ) V_47 << 4 ) | V_23 , ( ( T_1 ) V_47 << 4 ) | ( V_23 - 1 ) ) ;
if ( V_33 ) if ( ( V_86 = F_34 ( V_7 -> V_66 , F_23 ( V_5 ) , & V_50 ) ) ) {
V_86 -> V_47 = F_27 ( V_82 ) ;
F_35 ( & V_50 ) ;
F_36 ( & V_50 ) ;
}
F_37 ( V_7 , V_82 , V_89 -> V_37 , V_89 -> V_38 , V_89 , V_92 ) ;
V_43 = V_47 ;
F_11 ( V_89 ) ;
goto V_83;
}
V_90:
F_35 ( & V_45 ) ;
V_84:
F_36 ( & V_45 ) ;
}
int F_50 ( struct V_10 * V_7 , T_2 V_43 , struct V_3 * V_5 ,
struct V_44 * V_45 , int V_94 )
{
struct V_1 * V_1 = V_45 -> V_95 ;
T_2 V_33 = 0 ;
T_1 V_24 ;
if ( V_5 -> V_96 || V_5 -> V_41 ) {
F_21 ( V_7 -> V_66 , L_33 , V_43 ) ;
F_36 ( V_45 ) ;
return 1 ;
}
if ( V_5 -> V_33 ) V_33 = F_23 ( V_5 ) ;
if ( V_94 && ( V_5 -> V_33 || ( V_5 == F_3 ( V_1 ) && F_4 ( V_5 ) -> V_41 ) ) ) {
if ( F_46 ( V_7 -> V_66 , V_97 ) ) {
F_36 ( V_45 ) ;
return 2 ;
}
}
V_7 -> V_76 ++ ;
F_13 ( V_7 , F_17 , ( V_24 = F_1 ( V_1 , V_5 ) ) + 1 , 1 ) ;
F_32 ( V_7 -> V_66 , V_1 , V_5 ) ;
F_35 ( V_45 ) ;
F_36 ( V_45 ) ;
if ( V_33 ) {
T_2 V_81 = F_47 ( V_7 , V_33 , V_43 ) ;
F_13 ( V_7 , F_15 , 5 , V_24 ) ;
if ( V_81 ) F_49 ( V_7 , V_81 ) ;
return ! V_81 ;
}
F_49 ( V_7 , V_43 ) ;
return 0 ;
}
void F_51 ( struct V_29 * V_30 , T_2 V_43 , int * V_98 ,
int * V_99 , int * V_100 )
{
struct V_1 * V_1 ;
struct V_44 V_45 ;
struct V_3 * V_5 ;
T_2 V_31 , V_101 = 0 ;
int V_63 , V_64 = 0 ;
int V_86 , V_102 = 0 ;
V_103:
if ( V_98 ) ( * V_98 ) ++ ;
if ( F_22 ( V_30 ) -> V_32 )
if ( F_38 ( V_30 , V_43 , & V_63 , & V_64 , L_34 ) ) return;
V_31 = 0 ;
V_65:
if ( ! ( V_1 = F_34 ( V_30 , V_43 , & V_45 ) ) ) return;
if ( F_22 ( V_30 ) -> V_32 ) if ( V_101 && V_101 != - 1 && F_5 ( V_1 -> V_47 ) != V_101 )
F_21 ( V_30 , L_35 , V_101 , V_43 , F_5 ( V_1 -> V_47 ) ) ;
V_5 = F_3 ( V_1 ) ;
if ( V_31 ) while( 1 ) {
if ( V_5 -> V_33 ) if ( F_23 ( V_5 ) == V_31 ) goto V_104;
if ( V_5 -> V_41 ) {
F_36 ( & V_45 ) ;
F_21 ( V_30 , L_36 ,
V_31 , V_43 , V_101 ) ;
return;
}
V_5 = F_4 ( V_5 ) ;
}
V_105:
if ( V_5 -> V_33 ) {
V_101 = V_43 ;
V_43 = F_23 ( V_5 ) ;
F_36 ( & V_45 ) ;
goto V_103;
}
V_104:
if ( ! V_5 -> V_96 && ! V_5 -> V_41 && V_5 -> V_106 && V_99 ) ( * V_99 ) ++ ;
if ( ! V_5 -> V_96 && ! V_5 -> V_41 && V_100 ) ( * V_100 ) ++ ;
if ( ( V_5 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) goto V_105;
V_31 = V_43 ;
V_43 = F_5 ( V_1 -> V_47 ) ;
if ( V_1 -> V_48 ) {
F_36 ( & V_45 ) ;
return;
}
F_36 ( & V_45 ) ;
if ( F_22 ( V_30 ) -> V_32 )
if ( F_38 ( V_30 , V_31 , & V_86 , & V_102 , L_37 ) ) return;
V_101 = - 1 ;
goto V_65;
}
static struct V_3 * F_52 ( struct V_29 * V_30 , T_2 V_43 , int V_26 ,
struct V_44 * V_45 , struct V_1 * * V_107 )
{
int V_7 ;
struct V_3 * V_5 , * V_6 ;
struct V_1 * V_1 ;
V_1 = F_34 ( V_30 , V_43 , V_45 ) ;
if ( ! V_1 ) return NULL ;
if ( V_107 ) * V_107 = V_1 ;
V_5 = F_3 ( V_1 ) ;
V_6 = F_2 ( V_1 ) ;
for ( V_7 = 1 ; V_5 < V_6 ; V_7 ++ , V_5 = F_4 ( V_5 ) ) {
if ( V_7 == V_26 ) {
return V_5 ;
}
if ( V_5 -> V_41 ) break;
}
F_36 ( V_45 ) ;
F_21 ( V_30 , L_38 , V_43 , V_26 ) ;
return NULL ;
}
T_2 F_53 ( struct V_29 * V_30 , T_2 V_43 )
{
struct V_44 V_45 ;
T_2 V_2 = V_43 ;
T_2 V_47 = 0 ;
struct V_3 * V_5 ;
int V_63 , V_64 = 0 ;
V_108:
if ( F_22 ( V_30 ) -> V_32 )
if ( F_38 ( V_30 , V_2 , & V_63 , & V_64 , L_39 ) )
return V_2 ;
if ( ! ( V_5 = F_52 ( V_30 , V_2 , 1 , & V_45 , NULL ) ) ) return V_43 ;
if ( F_22 ( V_30 ) -> V_32 )
if ( V_47 && F_5 ( ( (struct V_1 * ) V_45 . V_95 ) -> V_47 ) != V_47 )
F_21 ( V_30 , L_40 , V_47 , V_2 , F_5 ( ( (struct V_1 * ) V_45 . V_95 ) -> V_47 ) ) ;
if ( ! V_5 -> V_33 ) {
F_36 ( & V_45 ) ;
return V_2 ;
}
V_47 = V_2 ;
V_2 = F_23 ( V_5 ) ;
F_36 ( & V_45 ) ;
goto V_108;
}
struct V_3 * F_54 ( struct V_10 * V_10 , T_1 * V_109 ,
struct V_44 * V_45 )
{
T_1 V_11 ;
unsigned V_25 ;
T_2 V_43 ;
struct V_3 * V_5 , * V_2 ;
struct V_3 * V_110 ;
struct V_3 * V_111 ;
struct V_1 * V_1 ;
struct V_1 * V_112 ;
struct V_44 V_113 ;
V_11 = * V_109 ;
V_43 = V_11 >> 6 << 2 ;
V_11 &= 077 ;
if ( ! ( V_5 = F_52 ( V_10 -> V_66 , V_43 , V_11 , V_45 , & V_1 ) ) )
goto V_114;
if ( ( V_2 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) {
if ( ! ( ++ * V_109 & 077 ) ) {
F_21 ( V_10 -> V_66 ,
L_41 ,
( unsigned long long ) * V_109 ) ;
goto V_114;
}
if ( V_2 -> V_33 ) {
* V_109 = ( ( T_1 ) F_53 ( V_10 -> V_66 , F_23 ( V_2 ) ) << 4 ) + 1 ;
}
return V_5 ;
}
if ( V_1 -> V_48 ) goto V_114;
if ( ! ( V_112 = F_34 ( V_10 -> V_66 , F_5 ( V_1 -> V_47 ) , & V_113 ) ) )
goto V_114;
V_111 = F_2 ( V_112 ) ;
V_25 = 0 ;
for ( V_110 = F_3 ( V_112 ) ; V_110 < V_111 ;
V_110 = F_4 ( V_110 ) ) {
if ( ! ( ++ V_25 & 077 ) ) F_21 ( V_10 -> V_66 ,
L_42 , F_5 ( V_1 -> V_47 ) ) ;
if ( V_110 -> V_33 && F_23 ( V_110 ) == V_43 ) {
* V_109 = ( ( T_1 ) F_5 ( V_1 -> V_47 ) << 4 ) + V_25 ;
F_36 ( & V_113 ) ;
return V_5 ;
}
}
F_21 ( V_10 -> V_66 , L_43 ,
V_43 , F_5 ( V_1 -> V_47 ) ) ;
F_36 ( & V_113 ) ;
V_114:
* V_109 = 12 ;
return V_5 ;
}
struct V_3 * F_55 ( struct V_10 * V_10 , T_2 V_43 ,
const unsigned char * V_37 , unsigned V_115 ,
T_2 * V_46 , struct V_44 * V_45 )
{
struct V_1 * V_1 ;
struct V_3 * V_5 ;
struct V_3 * V_6 ;
int V_63 , V_64 = 0 ;
if ( ! F_56 ( V_10 -> V_116 ) ) F_21 ( V_10 -> V_66 , L_44 ) ;
V_108:
if ( F_22 ( V_10 -> V_66 ) -> V_32 )
if ( F_38 ( V_10 -> V_66 , V_43 , & V_63 , & V_64 , L_45 ) ) return NULL ;
if ( ! ( V_1 = F_34 ( V_10 -> V_66 , V_43 , V_45 ) ) ) return NULL ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_24 = F_30 ( V_10 -> V_66 , V_37 , V_115 , V_5 -> V_37 , V_5 -> V_38 , V_5 -> V_41 ) ;
if ( ! V_24 ) {
if ( V_46 ) * V_46 = V_43 ;
return V_5 ;
}
if ( V_24 < 0 ) {
if ( V_5 -> V_33 ) {
V_43 = F_23 ( V_5 ) ;
F_36 ( V_45 ) ;
goto V_108;
}
break;
}
}
F_36 ( V_45 ) ;
return NULL ;
}
void F_57 ( struct V_29 * V_30 , T_2 V_43 )
{
struct V_44 V_45 ;
struct V_1 * V_1 ;
struct V_3 * V_5 ;
T_2 V_86 , V_102 , V_56 = V_43 ;
while ( 1 ) {
if ( ! ( V_1 = F_34 ( V_30 , V_43 , & V_45 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( V_5 -> V_41 ) {
if ( V_5 -> V_33 ) V_86 = F_23 ( V_5 ) ;
else goto error;
F_36 ( & V_45 ) ;
F_42 ( V_30 , V_43 ) ;
V_43 = V_86 ;
} else break;
}
if ( ! V_5 -> V_96 ) goto error;
V_86 = V_5 -> V_33 ? F_23 ( V_5 ) : 0 ;
V_5 = F_4 ( V_5 ) ;
if ( ! V_5 -> V_41 ) goto error;
V_102 = V_5 -> V_33 ? F_23 ( V_5 ) : 0 ;
F_36 ( & V_45 ) ;
F_42 ( V_30 , V_43 ) ;
do {
while ( V_86 ) {
if ( ! ( V_1 = F_34 ( V_30 , V_43 = V_86 , & V_45 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( ! V_5 -> V_41 ) goto error;
V_86 = V_5 -> V_33 ? F_23 ( V_5 ) : 0 ;
F_36 ( & V_45 ) ;
F_42 ( V_30 , V_43 ) ;
}
V_86 = V_102 ;
V_102 = 0 ;
} while ( V_86 );
return;
error:
F_36 ( & V_45 ) ;
F_42 ( V_30 , V_43 ) ;
F_21 ( V_30 , L_46 , V_56 ) ;
}
struct V_3 * F_58 ( struct V_29 * V_30 , T_4 V_117 ,
struct V_62 * F_14 , struct V_44 * V_45 )
{
unsigned char * V_118 ;
unsigned char * V_119 ;
int V_120 , V_121 ;
struct V_1 * V_2 ;
T_2 V_43 , V_122 ;
struct V_62 * V_123 ;
struct V_60 * V_61 ;
struct V_3 * V_5 , * V_6 ;
int V_25 ;
int V_63 , V_64 = 0 ;
int V_86 , V_102 = 0 ;
V_118 = F_14 -> V_37 ;
if ( ! ( V_119 = F_9 ( 256 , V_16 ) ) ) {
F_10 ( L_47 ) ;
return NULL ;
}
if ( F_14 -> V_115 <= 15 )
memcpy ( V_119 , V_118 , V_120 = V_121 = F_14 -> V_115 ) ;
else {
memcpy ( V_119 , V_118 , 15 ) ;
memset ( V_119 + 15 , 0xff , 256 - 15 ) ;
V_120 = 15 ; V_121 = 256 ;
}
if ( ! ( V_123 = F_41 ( V_30 , F_5 ( F_14 -> V_47 ) , & V_61 ) ) ) {
F_11 ( V_119 ) ;
return NULL ;
}
if ( ! F_59 ( V_123 ) ) {
F_44 ( V_61 ) ;
F_21 ( V_30 , L_48 , V_117 , F_5 ( F_14 -> V_47 ) ) ;
F_11 ( V_119 ) ;
return NULL ;
}
V_43 = F_5 ( V_123 -> V_70 . V_71 [ 0 ] . V_72 ) ;
F_44 ( V_61 ) ;
V_103:
V_122 = 0 ;
V_65:
if ( ! ( V_2 = F_34 ( V_30 , V_43 , V_45 ) ) ) {
F_11 ( V_119 ) ;
return NULL ;
}
V_6 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_2 ) ;
if ( V_122 ) {
while ( V_5 < V_6 ) {
if ( V_5 -> V_33 ) if ( F_23 ( V_5 ) == V_122 ) goto F_14;
V_5 = F_4 ( V_5 ) ;
}
F_21 ( V_30 , L_49 , V_122 , V_43 ) ;
F_36 ( V_45 ) ;
F_11 ( V_119 ) ;
return NULL ;
}
V_105:
if ( F_5 ( V_5 -> V_62 ) == V_117 ) {
F_11 ( V_119 ) ;
return V_5 ;
}
V_25 = F_30 ( V_30 , V_118 , V_120 , V_5 -> V_37 , V_5 -> V_38 , V_5 -> V_41 ) ;
if ( V_25 < 0 && V_5 -> V_33 ) {
V_43 = F_23 ( V_5 ) ;
F_36 ( V_45 ) ;
if ( F_22 ( V_30 ) -> V_32 )
if ( F_38 ( V_30 , V_43 , & V_63 , & V_64 , L_50 ) ) {
F_11 ( V_119 ) ;
return NULL ;
}
goto V_103;
}
F_14:
if ( F_5 ( V_5 -> V_62 ) == V_117 ) {
F_11 ( V_119 ) ;
return V_5 ;
}
V_25 = F_30 ( V_30 , V_119 , V_121 , V_5 -> V_37 , V_5 -> V_38 , V_5 -> V_41 ) ;
if ( V_25 < 0 && ! V_5 -> V_41 ) goto V_124;
if ( ( V_5 = F_4 ( V_5 ) ) < V_6 ) goto V_105;
if ( V_2 -> V_48 ) goto V_124;
V_122 = V_43 ;
V_43 = F_5 ( V_2 -> V_47 ) ;
F_36 ( V_45 ) ;
if ( F_22 ( V_30 ) -> V_32 )
if ( F_38 ( V_30 , V_122 , & V_86 , & V_102 , L_51 ) ) {
F_11 ( V_119 ) ;
return NULL ;
}
goto V_65;
V_124:
F_36 ( V_45 ) ;
F_21 ( V_30 , L_52 , V_117 ) ;
F_11 ( V_119 ) ;
return NULL ;
}
