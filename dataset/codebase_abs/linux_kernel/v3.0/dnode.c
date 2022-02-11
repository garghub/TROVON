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
V_2 -> V_33 = F_24 ( F_5 ( V_2 -> V_33 ) + 4 ) ;
if ( F_5 ( V_2 -> V_33 ) > 2048 ) {
F_20 ( V_28 , L_8 , F_5 ( V_2 -> V_8 ) ) ;
V_2 -> V_33 = F_24 ( F_5 ( V_2 -> V_33 ) - 4 ) ;
return;
}
V_5 -> V_32 = F_25 ( 36 ) ;
V_5 -> V_31 = 1 ;
* ( T_2 * ) ( ( char * ) V_5 + 32 ) = F_24 ( V_29 ) ;
}
}
struct V_3 * F_26 ( struct V_27 * V_28 , struct V_1 * V_2 ,
const unsigned char * V_34 ,
unsigned V_35 , T_3 V_36 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
unsigned V_37 = F_27 ( V_35 , V_36 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_23 = F_28 ( V_28 , V_34 , V_35 , V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_38 ) ;
if ( ! V_23 ) {
F_20 ( V_28 , L_9 , * V_34 , V_35 , F_5 ( V_2 -> V_8 ) ) ;
return NULL ;
}
if ( V_23 < 0 ) break;
}
memmove ( ( char * ) V_5 + V_37 , V_5 , ( char * ) V_6 - ( char * ) V_5 ) ;
memset ( V_5 , 0 , V_37 ) ;
if ( V_36 ) {
* ( T_2 * ) ( ( char * ) V_5 + V_37 - 4 ) = F_24 ( V_36 ) ;
V_5 -> V_31 = 1 ;
}
V_5 -> V_32 = F_25 ( V_37 ) ;
V_5 -> V_39 = F_29 ( V_34 , V_35 ) ;
V_5 -> V_35 = V_35 ;
memcpy ( V_5 -> V_34 , V_34 , V_35 ) ;
V_2 -> V_33 = F_24 ( F_5 ( V_2 -> V_33 ) + V_37 ) ;
return V_5 ;
}
static void F_30 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_3 * V_5 )
{
if ( V_5 -> V_38 ) {
F_20 ( V_28 , L_10 , F_5 ( V_2 -> V_8 ) ) ;
return;
}
V_2 -> V_33 = F_24 ( F_5 ( V_2 -> V_33 ) - F_23 ( V_5 -> V_32 ) ) ;
memmove ( V_5 , F_4 ( V_5 ) , F_5 ( V_2 -> V_33 ) + ( char * ) V_2 - ( char * ) V_5 ) ;
}
static void F_31 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_3 * V_6 = F_2 ( V_2 ) ;
T_2 V_40 = F_5 ( V_2 -> V_8 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) )
if ( V_5 -> V_31 ) {
struct V_41 V_42 ;
struct V_1 * V_43 ;
if ( ( V_43 = F_32 ( V_28 , F_22 ( V_5 ) , & V_42 ) ) ) {
if ( F_5 ( V_43 -> V_44 ) != V_40 || V_43 -> V_45 ) {
V_43 -> V_44 = F_24 ( V_40 ) ;
V_43 -> V_45 = 0 ;
F_33 ( & V_42 ) ;
}
F_34 ( & V_42 ) ;
}
}
}
static int F_35 ( struct V_9 * V_7 , T_2 V_40 ,
const unsigned char * V_34 , unsigned V_35 ,
struct V_3 * V_46 , T_2 V_36 )
{
struct V_41 V_42 , V_47 , V_48 ;
struct V_1 * V_2 , * V_49 , * V_50 , * V_51 = NULL ;
T_2 V_52 , V_53 ;
struct V_3 * V_5 ;
struct V_3 V_54 ;
unsigned char * V_55 ;
int V_56 ;
int V_10 ;
struct V_57 * V_58 ;
struct V_59 * V_59 ;
int V_60 , V_61 = 0 ;
if ( ! ( V_55 = F_9 ( 256 , V_15 ) ) ) {
F_6 ( L_11 ) ;
return 1 ;
}
V_62:
if ( V_35 >= 256 ) {
F_20 ( V_7 -> V_63 , L_12 , V_35 ) ;
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
if ( ! ( V_2 = F_32 ( V_7 -> V_63 , V_40 , & V_42 ) ) ) {
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
V_64:
if ( F_21 ( V_7 -> V_63 ) -> V_30 )
if ( F_36 ( V_7 -> V_63 , V_40 , & V_60 , & V_61 , L_13 ) ) {
F_34 ( & V_42 ) ;
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
if ( F_5 ( V_2 -> V_33 ) + F_27 ( V_35 , V_36 ) <= 2048 ) {
T_1 V_22 ;
F_37 ( V_5 = F_26 ( V_7 -> V_63 , V_2 , V_34 , V_35 , V_36 ) , V_46 ) ;
V_22 = F_1 ( V_2 , V_5 ) ;
F_12 ( V_7 , F_15 , V_22 , 1 ) ;
F_12 ( V_7 , F_14 , 4 , V_22 ) ;
F_12 ( V_7 , F_14 , 5 , V_22 + 1 ) ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 0 ;
}
if ( ! V_51 ) if ( ! ( V_51 = F_9 ( 0x924 , V_15 ) ) ) {
F_6 ( L_14 ) ;
F_34 ( & V_42 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
memcpy ( V_51 , V_2 , F_5 ( V_2 -> V_33 ) ) ;
F_37 ( V_5 = F_26 ( V_7 -> V_63 , V_51 , V_34 , V_35 , V_36 ) , V_46 ) ;
F_12 ( V_7 , F_15 , F_1 ( V_51 , V_5 ) , 1 ) ;
V_56 = ( ( char * ) F_18 ( V_51 ) - ( char * ) V_51 ) / 2 + 10 ;
if ( ! ( V_49 = F_38 ( V_7 -> V_63 , F_5 ( V_2 -> V_44 ) , & V_52 , & V_47 ) ) ) {
F_20 ( V_7 -> V_63 , L_15 ) ;
F_34 ( & V_42 ) ;
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
V_7 -> V_65 += 2048 ;
V_7 -> V_66 += 4 ;
V_10 = 1 ;
for ( V_5 = F_3 ( V_51 ) ; ( char * ) F_4 ( V_5 ) - ( char * ) V_51 < V_56 ; V_5 = F_4 ( V_5 ) ) {
F_37 ( F_26 ( V_7 -> V_63 , V_49 , V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_31 ? F_22 ( V_5 ) : 0 ) , V_5 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_40 << 4 ) | V_10 , ( ( T_1 ) V_52 << 4 ) | V_10 ) ;
V_10 ++ ;
}
F_37 ( V_46 = & V_54 , V_5 ) ;
memcpy ( V_55 , V_5 -> V_34 , V_5 -> V_35 ) ;
V_34 = V_55 ;
V_35 = V_5 -> V_35 ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_40 << 4 ) | V_10 , 4 ) ;
V_36 = V_52 ;
F_19 ( V_7 -> V_63 , V_49 , V_5 -> V_31 ? F_22 ( V_5 ) : 0 ) ;
V_5 = F_4 ( V_5 ) ;
memmove ( ( char * ) V_51 + 20 , V_5 , F_5 ( V_51 -> V_33 ) + ( char * ) V_51 - ( char * ) V_5 ) ;
V_51 -> V_33 = F_24 ( F_5 ( V_51 -> V_33 ) - ( ( char * ) V_5 - ( char * ) V_51 - 20 ) ) ;
memcpy ( V_2 , V_51 , F_5 ( V_51 -> V_33 ) ) ;
F_12 ( V_7 , F_16 , ( T_1 ) V_40 << 4 , V_10 ) ;
F_31 ( V_7 -> V_63 , V_49 ) ;
if ( ! V_2 -> V_45 ) {
V_49 -> V_44 = V_2 -> V_44 ;
V_40 = F_5 ( V_49 -> V_44 ) ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
goto V_62;
}
if ( ! ( V_50 = F_38 ( V_7 -> V_63 , F_5 ( V_2 -> V_44 ) , & V_53 , & V_48 ) ) ) {
F_20 ( V_7 -> V_63 , L_15 ) ;
F_34 ( & V_42 ) ;
F_34 ( & V_47 ) ;
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
V_7 -> V_65 += 2048 ;
V_7 -> V_66 += 4 ;
V_50 -> V_45 = 1 ;
V_50 -> V_44 = V_2 -> V_44 ;
if ( ! ( V_59 = F_39 ( V_7 -> V_63 , F_5 ( V_2 -> V_44 ) , & V_58 ) ) ) {
F_40 ( V_7 -> V_63 , V_53 ) ;
F_34 ( & V_42 ) ;
F_34 ( & V_47 ) ;
F_34 ( & V_48 ) ;
F_10 ( V_51 ) ;
F_10 ( V_55 ) ;
return 1 ;
}
V_59 -> V_67 . V_68 [ 0 ] . V_69 = F_24 ( V_53 ) ;
F_41 ( V_58 ) ;
F_42 ( V_58 ) ;
F_8 ( V_7 ) -> V_70 = V_53 ;
V_2 -> V_44 = V_49 -> V_44 = F_24 ( V_53 ) ;
V_2 -> V_45 = V_49 -> V_45 = 0 ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
V_42 = V_48 ;
F_19 ( V_7 -> V_63 , V_50 , V_40 ) ;
V_40 = V_53 ;
V_2 = V_50 ;
goto V_64;
}
int F_43 ( struct V_9 * V_7 ,
const unsigned char * V_34 , unsigned V_35 ,
struct V_3 * V_46 )
{
struct V_11 * V_12 = F_8 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_3 * V_5 , * V_6 ;
struct V_41 V_42 ;
T_2 V_40 ;
int V_23 ;
int V_60 , V_61 = 0 ;
V_40 = V_12 -> V_70 ;
V_31:
if ( F_21 ( V_7 -> V_63 ) -> V_30 )
if ( F_36 ( V_7 -> V_63 , V_40 , & V_60 , & V_61 , L_16 ) ) return 1 ;
if ( ! ( V_2 = F_32 ( V_7 -> V_63 , V_40 , & V_42 ) ) ) return 1 ;
V_6 = F_2 ( V_2 ) ;
for ( V_5 = F_3 ( V_2 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
if ( ! ( V_23 = F_28 ( V_7 -> V_63 , V_34 , V_35 , V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_38 ) ) ) {
F_34 ( & V_42 ) ;
return - 1 ;
}
if ( V_23 < 0 ) {
if ( V_5 -> V_31 ) {
V_40 = F_22 ( V_5 ) ;
F_34 ( & V_42 ) ;
goto V_31;
}
break;
}
}
F_34 ( & V_42 ) ;
if ( F_44 ( V_7 -> V_63 , V_71 ) ) {
V_23 = 1 ;
goto V_72;
}
V_7 -> V_73 ++ ;
V_23 = F_35 ( V_7 , V_40 , V_34 , V_35 , V_46 , 0 ) ;
V_72:
return V_23 ;
}
static T_3 F_45 ( struct V_9 * V_7 , T_2 V_74 , T_2 V_75 )
{
T_2 V_40 , V_76 ;
T_2 V_77 = V_75 ;
struct V_1 * V_1 ;
struct V_41 V_42 ;
struct V_3 * V_5 , * V_54 ;
int V_78 ;
T_1 V_22 ;
int V_60 , V_61 = 0 ;
V_40 = V_74 ;
while ( 1 ) {
if ( F_21 ( V_7 -> V_63 ) -> V_30 )
if ( F_36 ( V_7 -> V_63 , V_40 , & V_60 , & V_61 , L_17 ) )
return 0 ;
if ( ! ( V_1 = F_32 ( V_7 -> V_63 , V_40 , & V_42 ) ) ) return 0 ;
if ( F_21 ( V_7 -> V_63 ) -> V_30 ) {
if ( F_5 ( V_1 -> V_44 ) != V_77 ) {
F_20 ( V_7 -> V_63 , L_18 ,
V_40 , V_77 , F_5 ( V_1 -> V_44 ) ) ;
F_34 ( & V_42 ) ;
return 0 ;
}
V_77 = V_40 ;
}
if ( ! ( V_5 = F_18 ( V_1 ) ) ) {
F_20 ( V_7 -> V_63 , L_19 , V_40 ) ;
F_34 ( & V_42 ) ;
return 0 ;
}
if ( ! V_5 -> V_31 ) break;
V_40 = F_22 ( V_5 ) ;
F_34 ( & V_42 ) ;
}
while ( ! ( V_5 = F_17 ( V_1 ) ) ) {
T_2 V_44 = F_5 ( V_1 -> V_44 ) ;
F_34 ( & V_42 ) ;
F_40 ( V_7 -> V_63 , V_40 ) ;
V_7 -> V_65 -= 2048 ;
V_7 -> V_66 -= 4 ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_40 << 4 ) | 1 , 5 ) ;
if ( V_44 == V_75 ) return V_75 ;
if ( ! ( V_1 = F_32 ( V_7 -> V_63 , V_44 , & V_42 ) ) ) return 0 ;
if ( V_1 -> V_45 ) {
F_20 ( V_7 -> V_63 , L_20 , V_74 , V_75 ) ;
F_34 ( & V_42 ) ;
return 0 ;
}
V_5 = F_18 ( V_1 ) ;
if ( ! V_5 || ! V_5 -> V_31 ) {
F_20 ( V_7 -> V_63 , L_21 , V_44 , V_40 ) ;
F_34 ( & V_42 ) ;
return 0 ;
}
V_1 -> V_33 = F_24 ( F_5 ( V_1 -> V_33 ) - 4 ) ;
V_5 -> V_32 = F_25 ( F_23 ( V_5 -> V_32 ) - 4 ) ;
V_5 -> V_31 = 0 ;
F_33 ( & V_42 ) ;
V_40 = V_44 ;
}
V_22 = F_1 ( V_1 , V_5 ) ;
F_12 ( V_7 , F_14 , V_22 , 4 ) ;
F_12 ( V_7 , F_14 , V_22 + 1 , 5 ) ;
if ( ! ( V_54 = F_9 ( F_23 ( V_5 -> V_32 ) , V_15 ) ) ) {
F_20 ( V_7 -> V_63 , L_22 ) ;
F_34 ( & V_42 ) ;
return 0 ;
}
memcpy ( V_54 , V_5 , F_23 ( V_5 -> V_32 ) ) ;
V_76 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
F_30 ( V_7 -> V_63 , V_1 , V_5 ) ;
F_19 ( V_7 -> V_63 , V_1 , V_76 ) ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
V_78 = F_35 ( V_7 , V_75 , V_54 -> V_34 , V_54 -> V_35 , V_54 , V_74 ) ;
F_10 ( V_54 ) ;
if ( V_78 ) return 0 ;
return V_40 ;
}
static void F_46 ( struct V_9 * V_7 , T_2 V_40 )
{
struct V_11 * V_12 = F_8 ( V_7 ) ;
struct V_41 V_42 ;
struct V_1 * V_1 ;
T_2 V_31 , V_44 , V_79 ;
int V_21 ;
struct V_3 * V_5 ;
int V_60 , V_61 = 0 ;
V_80:
if ( F_36 ( V_7 -> V_63 , V_40 , & V_60 , & V_61 , L_23 ) ) return;
if ( ! ( V_1 = F_32 ( V_7 -> V_63 , V_40 , & V_42 ) ) ) return;
if ( F_5 ( V_1 -> V_33 ) > 56 ) goto V_81;
if ( F_5 ( V_1 -> V_33 ) == 52 || F_5 ( V_1 -> V_33 ) == 56 ) {
struct V_3 * V_6 ;
int V_82 = V_1 -> V_45 ;
V_44 = F_5 ( V_1 -> V_44 ) ;
V_5 = F_3 ( V_1 ) ;
V_31 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
if ( F_21 ( V_7 -> V_63 ) -> V_30 ) if ( V_82 && ! V_31 ) {
F_20 ( V_7 -> V_63 , L_24 , V_40 ) ;
goto V_81;
}
F_34 ( & V_42 ) ;
F_40 ( V_7 -> V_63 , V_40 ) ;
V_7 -> V_65 -= 2048 ;
V_7 -> V_66 -= 4 ;
if ( V_82 ) {
struct V_59 * V_59 ;
struct V_57 * V_58 ;
struct V_1 * V_83 ;
struct V_41 V_47 ;
if ( F_21 ( V_7 -> V_63 ) -> V_30 )
if ( V_44 != V_7 -> V_84 ) {
F_20 ( V_7 -> V_63 ,
L_25 ,
V_40 , V_44 , ( unsigned long ) V_7 -> V_84 ) ;
return;
}
if ( ( V_83 = F_32 ( V_7 -> V_63 , V_31 , & V_47 ) ) ) {
V_83 -> V_44 = F_24 ( V_44 ) ;
V_83 -> V_45 = 1 ;
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
}
if ( ( V_59 = F_39 ( V_7 -> V_63 , V_44 , & V_58 ) ) ) {
V_59 -> V_67 . V_68 [ 0 ] . V_69 = F_24 ( V_31 ) ;
F_41 ( V_58 ) ;
F_42 ( V_58 ) ;
}
V_12 -> V_70 = V_31 ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_40 << 4 ) | 1 , ( T_1 ) 12 ) ;
return;
}
if ( ! ( V_1 = F_32 ( V_7 -> V_63 , V_44 , & V_42 ) ) ) return;
V_21 = 1 ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) , V_21 ++ )
if ( V_5 -> V_31 ) if ( F_22 ( V_5 ) == V_40 ) goto V_18;
F_20 ( V_7 -> V_63 , L_26 , V_40 , V_44 ) ;
goto V_81;
V_18:
F_12 ( V_7 , F_14 , ( ( T_1 ) V_40 << 4 ) | 1 , ( ( T_1 ) V_44 << 4 ) | V_21 ) ;
if ( ! V_31 ) {
V_5 -> V_31 = 0 ;
V_5 -> V_32 = F_25 ( F_23 ( V_5 -> V_32 ) - 4 ) ;
V_1 -> V_33 = F_24 ( F_5 ( V_1 -> V_33 ) - 4 ) ;
memmove ( F_4 ( V_5 ) , ( char * ) F_4 ( V_5 ) + 4 ,
( char * ) V_1 + F_5 ( V_1 -> V_33 ) - ( char * ) F_4 ( V_5 ) ) ;
} else {
struct V_1 * V_83 ;
struct V_41 V_47 ;
* ( T_2 * ) ( ( void * ) V_5 + F_23 ( V_5 -> V_32 ) - 4 ) = V_31 ;
if ( ( V_83 = F_32 ( V_7 -> V_63 , V_31 , & V_47 ) ) ) {
V_83 -> V_44 = F_24 ( V_44 ) ;
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
}
}
} else {
F_20 ( V_7 -> V_63 , L_27 , V_40 , F_5 ( V_1 -> V_33 ) ) ;
goto V_81;
}
if ( ! V_5 -> V_38 ) {
struct V_3 * V_85 = F_4 ( V_5 ) ;
struct V_3 * V_86 ;
struct V_1 * V_83 ;
struct V_41 V_47 ;
if ( ! V_85 -> V_31 ) goto V_87;
V_79 = F_22 ( V_85 ) ;
if ( ! ( V_86 = F_9 ( F_23 ( V_5 -> V_32 ) , V_15 ) ) ) {
F_6 ( L_28 ) ;
goto V_87;
}
memcpy ( V_86 , V_5 , F_23 ( V_5 -> V_32 ) ) ;
F_30 ( V_7 -> V_63 , V_1 , V_5 ) ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_44 << 4 ) | V_21 , 4 ) ;
F_12 ( V_7 , F_16 , ( ( T_1 ) V_44 << 4 ) | V_21 , 1 ) ;
if ( V_86 -> V_31 ) if ( ( V_83 = F_32 ( V_7 -> V_63 , F_22 ( V_86 ) , & V_47 ) ) ) {
V_83 -> V_44 = F_24 ( V_79 ) ;
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
}
F_35 ( V_7 , V_79 , V_86 -> V_34 , V_86 -> V_35 , V_86 , V_86 -> V_31 ? F_22 ( V_86 ) : 0 ) ;
V_40 = V_44 ;
F_10 ( V_86 ) ;
goto V_80;
} else {
struct V_3 * V_88 = F_17 ( V_1 ) ;
struct V_3 * V_86 ;
struct V_1 * V_83 ;
struct V_41 V_47 ;
T_2 V_89 ;
if ( ! V_88 ) {
F_20 ( V_7 -> V_63 , L_29 , V_44 ) ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
V_40 = V_44 ;
goto V_80;
}
if ( ! V_88 -> V_31 ) goto V_87;
V_79 = F_22 ( V_88 ) ;
if ( ( V_83 = F_32 ( V_7 -> V_63 , V_79 , & V_47 ) ) ) {
struct V_3 * V_90 = F_18 ( V_83 ) ;
V_89 = V_90 -> V_31 ? F_22 ( V_90 ) : 0 ;
if ( ! V_89 && V_31 ) {
if ( F_5 ( V_83 -> V_33 ) > 2044 ) {
if ( F_21 ( V_7 -> V_63 ) -> V_30 >= 2 ) {
F_6 ( L_30 ) ;
F_6 ( L_31 ) ;
}
F_34 ( & V_47 ) ;
goto V_87;
}
if ( F_21 ( V_7 -> V_63 ) -> V_30 >= 2 ) {
F_6 ( L_30 ) ;
F_6 ( L_32 ) ;
}
V_90 -> V_32 = F_25 ( F_23 ( V_90 -> V_32 ) + 4 ) ;
V_90 -> V_31 = 1 ;
V_83 -> V_33 = F_24 ( F_5 ( V_83 -> V_33 ) + 4 ) ;
}
if ( V_89 && ! V_31 ) {
V_90 -> V_32 = F_25 ( F_23 ( V_90 -> V_32 ) - 4 ) ;
V_90 -> V_31 = 0 ;
V_83 -> V_33 = F_24 ( F_5 ( V_83 -> V_33 ) - 4 ) ;
} else if ( V_31 )
* ( T_2 * ) ( ( void * ) V_90 + F_23 ( V_90 -> V_32 ) - 4 ) = F_24 ( V_31 ) ;
} else goto V_87;
if ( ! ( V_86 = F_9 ( F_23 ( V_88 -> V_32 ) , V_15 ) ) ) {
F_6 ( L_28 ) ;
F_34 ( & V_47 ) ;
goto V_87;
}
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
memcpy ( V_86 , V_88 , F_23 ( V_88 -> V_32 ) ) ;
F_30 ( V_7 -> V_63 , V_1 , V_88 ) ;
if ( ! V_88 -> V_31 ) {
V_88 -> V_32 = F_25 ( F_23 ( V_88 -> V_32 ) + 4 ) ;
V_88 -> V_31 = 1 ;
V_1 -> V_33 = F_24 ( F_5 ( V_1 -> V_33 ) + 4 ) ;
}
* ( T_2 * ) ( ( void * ) V_88 + F_23 ( V_88 -> V_32 ) - 4 ) = F_24 ( V_79 ) ;
F_33 ( & V_42 ) ;
F_34 ( & V_42 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_44 << 4 ) | ( V_21 - 1 ) , 4 ) ;
F_12 ( V_7 , F_14 , ( ( T_1 ) V_44 << 4 ) | V_21 , ( ( T_1 ) V_44 << 4 ) | ( V_21 - 1 ) ) ;
if ( V_31 ) if ( ( V_83 = F_32 ( V_7 -> V_63 , F_22 ( V_5 ) , & V_47 ) ) ) {
V_83 -> V_44 = F_24 ( V_79 ) ;
F_33 ( & V_47 ) ;
F_34 ( & V_47 ) ;
}
F_35 ( V_7 , V_79 , V_86 -> V_34 , V_86 -> V_35 , V_86 , V_89 ) ;
V_40 = V_44 ;
F_10 ( V_86 ) ;
goto V_80;
}
V_87:
F_33 ( & V_42 ) ;
V_81:
F_34 ( & V_42 ) ;
}
int F_47 ( struct V_9 * V_7 , T_2 V_40 , struct V_3 * V_5 ,
struct V_41 * V_42 , int V_91 )
{
struct V_1 * V_1 = V_42 -> V_92 ;
T_2 V_31 = 0 ;
T_1 V_22 ;
if ( V_5 -> V_93 || V_5 -> V_38 ) {
F_20 ( V_7 -> V_63 , L_33 , V_40 ) ;
F_34 ( V_42 ) ;
return 1 ;
}
if ( V_5 -> V_31 ) V_31 = F_22 ( V_5 ) ;
if ( V_91 && ( V_5 -> V_31 || ( V_5 == F_3 ( V_1 ) && F_4 ( V_5 ) -> V_38 ) ) ) {
if ( F_44 ( V_7 -> V_63 , V_94 ) ) {
F_34 ( V_42 ) ;
return 2 ;
}
}
V_7 -> V_73 ++ ;
F_12 ( V_7 , F_16 , ( V_22 = F_1 ( V_1 , V_5 ) ) + 1 , 1 ) ;
F_30 ( V_7 -> V_63 , V_1 , V_5 ) ;
F_33 ( V_42 ) ;
F_34 ( V_42 ) ;
if ( V_31 ) {
T_2 V_78 = F_45 ( V_7 , V_31 , V_40 ) ;
F_12 ( V_7 , F_14 , 5 , V_22 ) ;
if ( V_78 ) F_46 ( V_7 , V_78 ) ;
return ! V_78 ;
}
F_46 ( V_7 , V_40 ) ;
return 0 ;
}
void F_48 ( struct V_27 * V_28 , T_2 V_40 , int * V_95 ,
int * V_96 , int * V_97 )
{
struct V_1 * V_1 ;
struct V_41 V_42 ;
struct V_3 * V_5 ;
T_2 V_29 , V_98 = 0 ;
int V_60 , V_61 = 0 ;
int V_83 , V_99 = 0 ;
V_100:
if ( V_95 ) ( * V_95 ) ++ ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_36 ( V_28 , V_40 , & V_60 , & V_61 , L_34 ) ) return;
V_29 = 0 ;
V_62:
if ( ! ( V_1 = F_32 ( V_28 , V_40 , & V_42 ) ) ) return;
if ( F_21 ( V_28 ) -> V_30 ) if ( V_98 && V_98 != - 1 && F_5 ( V_1 -> V_44 ) != V_98 )
F_20 ( V_28 , L_35 , V_98 , V_40 , F_5 ( V_1 -> V_44 ) ) ;
V_5 = F_3 ( V_1 ) ;
if ( V_29 ) while( 1 ) {
if ( V_5 -> V_31 ) if ( F_22 ( V_5 ) == V_29 ) goto V_101;
if ( V_5 -> V_38 ) {
F_34 ( & V_42 ) ;
F_20 ( V_28 , L_36 ,
V_29 , V_40 , V_98 ) ;
return;
}
V_5 = F_4 ( V_5 ) ;
}
V_102:
if ( V_5 -> V_31 ) {
V_98 = V_40 ;
V_40 = F_22 ( V_5 ) ;
F_34 ( & V_42 ) ;
goto V_100;
}
V_101:
if ( ! V_5 -> V_93 && ! V_5 -> V_38 && V_5 -> V_103 && V_96 ) ( * V_96 ) ++ ;
if ( ! V_5 -> V_93 && ! V_5 -> V_38 && V_97 ) ( * V_97 ) ++ ;
if ( ( V_5 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) goto V_102;
V_29 = V_40 ;
V_40 = F_5 ( V_1 -> V_44 ) ;
if ( V_1 -> V_45 ) {
F_34 ( & V_42 ) ;
return;
}
F_34 ( & V_42 ) ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_36 ( V_28 , V_29 , & V_83 , & V_99 , L_37 ) ) return;
V_98 = - 1 ;
goto V_62;
}
static struct V_3 * F_49 ( struct V_27 * V_28 , T_2 V_40 , int V_24 ,
struct V_41 * V_42 , struct V_1 * * V_104 )
{
int V_7 ;
struct V_3 * V_5 , * V_6 ;
struct V_1 * V_1 ;
V_1 = F_32 ( V_28 , V_40 , V_42 ) ;
if ( ! V_1 ) return NULL ;
if ( V_104 ) * V_104 = V_1 ;
V_5 = F_3 ( V_1 ) ;
V_6 = F_2 ( V_1 ) ;
for ( V_7 = 1 ; V_5 < V_6 ; V_7 ++ , V_5 = F_4 ( V_5 ) ) {
if ( V_7 == V_24 ) {
return V_5 ;
}
if ( V_5 -> V_38 ) break;
}
F_34 ( V_42 ) ;
F_20 ( V_28 , L_38 , V_40 , V_24 ) ;
return NULL ;
}
T_2 F_50 ( struct V_27 * V_28 , T_2 V_40 )
{
struct V_41 V_42 ;
T_2 V_2 = V_40 ;
T_2 V_44 = 0 ;
struct V_3 * V_5 ;
int V_60 , V_61 = 0 ;
V_105:
if ( F_21 ( V_28 ) -> V_30 )
if ( F_36 ( V_28 , V_2 , & V_60 , & V_61 , L_39 ) )
return V_2 ;
if ( ! ( V_5 = F_49 ( V_28 , V_2 , 1 , & V_42 , NULL ) ) ) return V_40 ;
if ( F_21 ( V_28 ) -> V_30 )
if ( V_44 && F_5 ( ( (struct V_1 * ) V_42 . V_92 ) -> V_44 ) != V_44 )
F_20 ( V_28 , L_40 , V_44 , V_2 , F_5 ( ( (struct V_1 * ) V_42 . V_92 ) -> V_44 ) ) ;
if ( ! V_5 -> V_31 ) {
F_34 ( & V_42 ) ;
return V_2 ;
}
V_44 = V_2 ;
V_2 = F_22 ( V_5 ) ;
F_34 ( & V_42 ) ;
goto V_105;
}
struct V_3 * F_51 ( struct V_9 * V_9 , T_1 * V_106 ,
struct V_41 * V_42 )
{
T_1 V_10 ;
unsigned V_23 ;
T_2 V_40 ;
struct V_3 * V_5 , * V_2 ;
struct V_3 * V_107 ;
struct V_3 * V_108 ;
struct V_1 * V_1 ;
struct V_1 * V_109 ;
struct V_41 V_110 ;
V_10 = * V_106 ;
V_40 = V_10 >> 6 << 2 ;
V_10 &= 077 ;
if ( ! ( V_5 = F_49 ( V_9 -> V_63 , V_40 , V_10 , V_42 , & V_1 ) ) )
goto V_111;
if ( ( V_2 = F_4 ( V_5 ) ) < F_2 ( V_1 ) ) {
if ( ! ( ++ * V_106 & 077 ) ) {
F_20 ( V_9 -> V_63 ,
L_41 ,
( unsigned long long ) * V_106 ) ;
goto V_111;
}
if ( V_2 -> V_31 ) {
* V_106 = ( ( T_1 ) F_50 ( V_9 -> V_63 , F_22 ( V_2 ) ) << 4 ) + 1 ;
}
return V_5 ;
}
if ( V_1 -> V_45 ) goto V_111;
if ( ! ( V_109 = F_32 ( V_9 -> V_63 , F_5 ( V_1 -> V_44 ) , & V_110 ) ) )
goto V_111;
V_108 = F_2 ( V_109 ) ;
V_23 = 0 ;
for ( V_107 = F_3 ( V_109 ) ; V_107 < V_108 ;
V_107 = F_4 ( V_107 ) ) {
if ( ! ( ++ V_23 & 077 ) ) F_20 ( V_9 -> V_63 ,
L_42 , F_5 ( V_1 -> V_44 ) ) ;
if ( V_107 -> V_31 && F_22 ( V_107 ) == V_40 ) {
* V_106 = ( ( T_1 ) F_5 ( V_1 -> V_44 ) << 4 ) + V_23 ;
F_34 ( & V_110 ) ;
return V_5 ;
}
}
F_20 ( V_9 -> V_63 , L_43 ,
V_40 , F_5 ( V_1 -> V_44 ) ) ;
F_34 ( & V_110 ) ;
V_111:
* V_106 = 12 ;
return V_5 ;
}
struct V_3 * F_52 ( struct V_9 * V_9 , T_2 V_40 ,
const unsigned char * V_34 , unsigned V_112 ,
T_2 * V_43 , struct V_41 * V_42 )
{
struct V_1 * V_1 ;
struct V_3 * V_5 ;
struct V_3 * V_6 ;
int V_60 , V_61 = 0 ;
if ( ! F_53 ( V_9 -> V_113 ) ) F_20 ( V_9 -> V_63 , L_44 ) ;
V_105:
if ( F_21 ( V_9 -> V_63 ) -> V_30 )
if ( F_36 ( V_9 -> V_63 , V_40 , & V_60 , & V_61 , L_45 ) ) return NULL ;
if ( ! ( V_1 = F_32 ( V_9 -> V_63 , V_40 , V_42 ) ) ) return NULL ;
V_6 = F_2 ( V_1 ) ;
for ( V_5 = F_3 ( V_1 ) ; V_5 < V_6 ; V_5 = F_4 ( V_5 ) ) {
int V_22 = F_28 ( V_9 -> V_63 , V_34 , V_112 , V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_38 ) ;
if ( ! V_22 ) {
if ( V_43 ) * V_43 = V_40 ;
return V_5 ;
}
if ( V_22 < 0 ) {
if ( V_5 -> V_31 ) {
V_40 = F_22 ( V_5 ) ;
F_34 ( V_42 ) ;
goto V_105;
}
break;
}
}
F_34 ( V_42 ) ;
return NULL ;
}
void F_54 ( struct V_27 * V_28 , T_2 V_40 )
{
struct V_41 V_42 ;
struct V_1 * V_1 ;
struct V_3 * V_5 ;
T_2 V_83 , V_99 , V_53 = V_40 ;
while ( 1 ) {
if ( ! ( V_1 = F_32 ( V_28 , V_40 , & V_42 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( V_5 -> V_38 ) {
if ( V_5 -> V_31 ) V_83 = F_22 ( V_5 ) ;
else goto error;
F_34 ( & V_42 ) ;
F_40 ( V_28 , V_40 ) ;
V_40 = V_83 ;
} else break;
}
if ( ! V_5 -> V_93 ) goto error;
V_83 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
V_5 = F_4 ( V_5 ) ;
if ( ! V_5 -> V_38 ) goto error;
V_99 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
F_34 ( & V_42 ) ;
F_40 ( V_28 , V_40 ) ;
do {
while ( V_83 ) {
if ( ! ( V_1 = F_32 ( V_28 , V_40 = V_83 , & V_42 ) ) ) return;
V_5 = F_3 ( V_1 ) ;
if ( ! V_5 -> V_38 ) goto error;
V_83 = V_5 -> V_31 ? F_22 ( V_5 ) : 0 ;
F_34 ( & V_42 ) ;
F_40 ( V_28 , V_40 ) ;
}
V_83 = V_99 ;
V_99 = 0 ;
} while ( V_83 );
return;
error:
F_34 ( & V_42 ) ;
F_40 ( V_28 , V_40 ) ;
F_20 ( V_28 , L_46 , V_53 ) ;
}
struct V_3 * F_55 ( struct V_27 * V_28 , T_4 V_114 ,
struct V_59 * F_13 , struct V_41 * V_42 )
{
unsigned char * V_115 ;
unsigned char * V_116 ;
int V_117 , V_118 ;
struct V_1 * V_2 ;
T_2 V_40 , V_119 ;
struct V_59 * V_120 ;
struct V_57 * V_58 ;
struct V_3 * V_5 , * V_6 ;
int V_23 ;
int V_60 , V_61 = 0 ;
int V_83 , V_99 = 0 ;
V_115 = F_13 -> V_34 ;
if ( ! ( V_116 = F_9 ( 256 , V_15 ) ) ) {
F_6 ( L_47 ) ;
return NULL ;
}
if ( F_13 -> V_112 <= 15 )
memcpy ( V_116 , V_115 , V_117 = V_118 = F_13 -> V_112 ) ;
else {
memcpy ( V_116 , V_115 , 15 ) ;
memset ( V_116 + 15 , 0xff , 256 - 15 ) ;
V_117 = 15 ; V_118 = 256 ;
}
if ( ! ( V_120 = F_39 ( V_28 , F_5 ( F_13 -> V_44 ) , & V_58 ) ) ) {
F_10 ( V_116 ) ;
return NULL ;
}
if ( ! V_120 -> V_121 ) {
F_42 ( V_58 ) ;
F_20 ( V_28 , L_48 , V_114 , F_5 ( F_13 -> V_44 ) ) ;
F_10 ( V_116 ) ;
return NULL ;
}
V_40 = F_5 ( V_120 -> V_67 . V_68 [ 0 ] . V_69 ) ;
F_42 ( V_58 ) ;
V_100:
V_119 = 0 ;
V_62:
if ( ! ( V_2 = F_32 ( V_28 , V_40 , V_42 ) ) ) {
F_10 ( V_116 ) ;
return NULL ;
}
V_6 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_2 ) ;
if ( V_119 ) {
while ( V_5 < V_6 ) {
if ( V_5 -> V_31 ) if ( F_22 ( V_5 ) == V_119 ) goto F_13;
V_5 = F_4 ( V_5 ) ;
}
F_20 ( V_28 , L_49 , V_119 , V_40 ) ;
F_34 ( V_42 ) ;
F_10 ( V_116 ) ;
return NULL ;
}
V_102:
if ( F_5 ( V_5 -> V_59 ) == V_114 ) {
F_10 ( V_116 ) ;
return V_5 ;
}
V_23 = F_28 ( V_28 , V_115 , V_117 , V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_38 ) ;
if ( V_23 < 0 && V_5 -> V_31 ) {
V_40 = F_22 ( V_5 ) ;
F_34 ( V_42 ) ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_36 ( V_28 , V_40 , & V_60 , & V_61 , L_50 ) ) {
F_10 ( V_116 ) ;
return NULL ;
}
goto V_100;
}
F_13:
if ( F_5 ( V_5 -> V_59 ) == V_114 ) {
F_10 ( V_116 ) ;
return V_5 ;
}
V_23 = F_28 ( V_28 , V_116 , V_118 , V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_38 ) ;
if ( V_23 < 0 && ! V_5 -> V_38 ) goto V_122;
if ( ( V_5 = F_4 ( V_5 ) ) < V_6 ) goto V_102;
if ( V_2 -> V_45 ) goto V_122;
V_119 = V_40 ;
V_40 = F_5 ( V_2 -> V_44 ) ;
F_34 ( V_42 ) ;
if ( F_21 ( V_28 ) -> V_30 )
if ( F_36 ( V_28 , V_119 , & V_83 , & V_99 , L_51 ) ) {
F_10 ( V_116 ) ;
return NULL ;
}
goto V_62;
V_122:
F_34 ( V_42 ) ;
F_20 ( V_28 , L_52 , V_114 ) ;
F_10 ( V_116 ) ;
return NULL ;
}
