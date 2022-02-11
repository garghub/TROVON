static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_9 -> V_12 = ( void * ) V_7 -> V_13 ;
V_9 -> V_14 = sizeof( struct V_15 ) ;
V_2 -> V_16 = V_9 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_17 ;
unsigned long V_18 ;
int V_19 ;
V_17 = F_2 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_17 )
return - V_11 ;
V_17 -> V_14 = sizeof( struct V_15 ) ;
V_17 -> V_12 = F_4 ( V_17 -> V_14 ) ;
if ( ! V_17 -> V_12 ) {
F_5 ( V_17 ) ;
F_6 ( V_20 L_1 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
memset ( V_17 -> V_12 , 0 , V_17 -> V_14 ) ;
F_7 ( & V_7 -> V_22 , V_18 ) ;
V_19 = F_8 ( & V_7 -> V_23 . V_24 ,
V_17 -> V_12 ,
& V_17 -> V_14 ) ;
F_9 ( & V_7 -> V_22 , V_18 ) ;
if ( V_19 != V_25 ) {
F_10 ( V_17 -> V_12 ) ;
V_17 -> V_12 = NULL ;
F_5 ( V_17 ) ;
F_6 ( V_20 L_2 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
V_2 -> V_16 = V_17 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_17 ;
unsigned long V_18 ;
int V_19 ;
V_17 = F_2 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_17 )
return - V_11 ;
V_17 -> V_14 = sizeof( struct V_15 ) ;
V_17 -> V_12 = F_4 ( V_17 -> V_14 ) ;
if ( ! V_17 -> V_12 ) {
F_5 ( V_17 ) ;
F_6 ( V_20 L_3 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
memset ( V_17 -> V_12 , 0 , V_17 -> V_14 ) ;
F_7 ( & V_7 -> V_22 , V_18 ) ;
V_19 = F_12 ( & V_7 -> V_23 . V_24 ,
V_17 -> V_12 ,
& V_17 -> V_14 ) ;
F_9 ( & V_7 -> V_22 , V_18 ) ;
if ( V_19 != V_25 ) {
F_10 ( V_17 -> V_12 ) ;
V_17 -> V_12 = NULL ;
F_5 ( V_17 ) ;
F_6 ( V_20 L_4 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
V_2 -> V_16 = V_17 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_8 * V_26 ;
V_26 = F_2 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_26 )
return - V_11 ;
V_26 -> V_5 = V_1 -> V_5 ;
V_2 -> V_16 = V_26 ;
return 0 ;
}
static T_1
F_14 ( struct V_2 * V_2 , T_1 V_27 , int V_28 )
{
struct V_8 * V_9 ;
T_1 V_29 = V_2 -> V_30 ;
V_9 = V_2 -> V_16 ;
switch ( V_28 ) {
case 0 :
V_2 -> V_30 = V_27 ;
break;
case 1 :
V_2 -> V_30 += V_27 ;
break;
case 2 :
V_2 -> V_30 = V_9 -> V_14 - V_27 ;
break;
default:
return - V_31 ;
}
if ( V_2 -> V_30 < 0 || V_2 -> V_30 > V_9 -> V_14 ) {
V_2 -> V_30 = V_29 ;
return - V_31 ;
}
return V_2 -> V_30 ;
}
static T_2
F_15 ( struct V_2 * V_2 , char T_3 * V_32 ,
T_4 V_33 , T_1 * V_29 )
{
struct V_8 * V_9 = V_2 -> V_16 ;
if ( ! V_9 || ! V_9 -> V_12 )
return 0 ;
return F_16 ( V_32 , V_33 , V_29 ,
V_9 -> V_12 , V_9 -> V_14 ) ;
}
static T_5
F_17 ( struct V_34 * V_23 , T_6 V_27 , T_6 V_35 )
{
T_7 V_36 ;
V_36 = ( V_27 >> 15 ) & 0x7 ;
if ( V_36 == 0 ) {
if ( ( V_27 + ( V_35 << 2 ) ) > 0x8000 )
return V_37 ;
} else if ( V_36 == 0x1 ) {
if ( ( V_27 + ( V_35 << 2 ) ) > 0x10000 )
return V_37 ;
} else {
if ( ( V_27 + ( V_35 << 2 ) ) > F_18 ( V_23 ) )
return V_37 ;
}
return V_25 ;
}
static T_2
F_19 ( struct V_2 * V_2 , char T_3 * V_32 ,
T_4 V_33 , T_1 * V_29 )
{
struct V_8 * V_38 = V_2 -> V_16 ;
struct V_3 * V_4 = (struct V_3 * ) V_38 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_2 V_19 ;
if ( ! V_7 -> V_39 )
return 0 ;
V_19 = F_16 ( V_32 , V_33 , V_29 ,
V_7 -> V_39 , V_7 -> V_40 ) ;
if ( ( * V_29 + V_33 ) >= V_7 -> V_40 ) {
F_5 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
V_7 -> V_40 = 0 ;
}
return V_19 ;
}
static T_2
F_20 ( struct V_2 * V_2 , const char T_3 * V_32 ,
T_4 V_33 , T_1 * V_41 )
{
struct V_8 * V_38 = V_2 -> V_16 ;
struct V_3 * V_4 = (struct V_3 * ) V_38 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_34 * V_23 = & V_7 -> V_23 ;
struct V_42 * V_24 = & V_23 -> V_24 ;
int V_43 , V_35 , V_19 , V_44 ;
T_6 * V_45 ;
void T_8 * V_46 , * V_47 ;
unsigned long V_18 ;
void * V_48 ;
V_48 = F_2 ( V_33 , V_10 ) ;
if ( ! V_48 ) {
F_6 ( V_20 L_5 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
if ( F_21 ( V_48 , ( void T_3 * ) V_32 , V_33 ) ) {
F_5 ( V_48 ) ;
return - V_11 ;
}
V_19 = sscanf ( V_48 , L_6 , & V_43 , & V_35 ) ;
if ( V_19 < 2 ) {
F_6 ( V_20
L_7 ,
V_7 -> V_21 , V_49 ) ;
F_5 ( V_48 ) ;
return - V_31 ;
}
F_5 ( V_48 ) ;
F_5 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
V_7 -> V_40 = 0 ;
V_7 -> V_39 = F_2 ( V_35 << 2 , V_10 ) ;
if ( ! V_7 -> V_39 ) {
F_6 ( V_20 L_8 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
V_7 -> V_40 = V_35 << 2 ;
V_46 = F_22 ( V_24 ) ;
V_43 &= F_18 ( V_23 ) ;
V_19 = F_17 ( V_23 , V_43 , V_35 ) ;
if ( V_19 ) {
F_6 ( V_20 L_9 ,
V_7 -> V_21 ) ;
F_5 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
V_7 -> V_40 = 0 ;
return - V_31 ;
}
V_47 = V_46 + V_43 ;
V_45 = ( T_6 * ) V_7 -> V_39 ;
F_7 ( & V_7 -> V_22 , V_18 ) ;
for ( V_44 = 0 ; V_44 < V_35 ; V_44 ++ ) {
* V_45 = F_23 ( V_47 ) ;
V_45 ++ ;
V_47 += sizeof( T_6 ) ;
}
F_9 ( & V_7 -> V_22 , V_18 ) ;
return V_33 ;
}
static T_2
F_24 ( struct V_2 * V_2 , const char T_3 * V_32 ,
T_4 V_33 , T_1 * V_41 )
{
struct V_8 * V_9 = V_2 -> V_16 ;
struct V_3 * V_4 = (struct V_3 * ) V_9 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_34 * V_23 = & V_7 -> V_23 ;
struct V_42 * V_24 = & V_23 -> V_24 ;
int V_43 , V_50 , V_19 ;
void T_8 * V_47 ;
unsigned long V_18 ;
void * V_48 ;
V_48 = F_2 ( V_33 , V_10 ) ;
if ( ! V_48 ) {
F_6 ( V_20 L_5 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
if ( F_21 ( V_48 , ( void T_3 * ) V_32 , V_33 ) ) {
F_5 ( V_48 ) ;
return - V_11 ;
}
V_19 = sscanf ( V_48 , L_6 , & V_43 , & V_50 ) ;
if ( V_19 < 2 ) {
F_6 ( V_20
L_7 ,
V_7 -> V_21 , V_49 ) ;
F_5 ( V_48 ) ;
return - V_31 ;
}
F_5 ( V_48 ) ;
V_43 &= F_18 ( V_23 ) ;
V_19 = F_17 ( V_23 , V_43 , 1 ) ;
if ( V_19 ) {
F_6 ( V_20
L_9 ,
V_7 -> V_21 ) ;
return - V_31 ;
}
V_47 = ( F_22 ( V_24 ) ) + V_43 ;
F_7 ( & V_7 -> V_22 , V_18 ) ;
F_25 ( V_50 , V_47 ) ;
F_9 ( & V_7 -> V_22 , V_18 ) ;
return V_33 ;
}
static int
F_26 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_16 ;
if ( ! V_9 )
return 0 ;
V_2 -> V_16 = NULL ;
F_5 ( V_9 ) ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_8 * V_17 = V_2 -> V_16 ;
if ( ! V_17 )
return 0 ;
if ( V_17 -> V_12 )
F_10 ( V_17 -> V_12 ) ;
V_2 -> V_16 = NULL ;
F_5 ( V_17 ) ;
return 0 ;
}
inline void
F_28 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
const struct V_51 * V_2 ;
char V_52 [ 64 ] ;
int V_44 ;
if ( ! V_53 )
return;
if ( ! V_54 ) {
V_54 = F_29 ( L_10 , NULL ) ;
F_30 ( & V_55 , 0 ) ;
if ( ! V_54 ) {
F_6 ( V_56
L_11 ) ;
goto V_57;
}
}
snprintf ( V_52 , sizeof( V_52 ) , L_12 , V_7 -> V_58 ) ;
if ( ! V_4 -> V_59 ) {
V_4 -> V_59 =
F_29 ( V_52 , V_54 ) ;
if ( ! V_4 -> V_59 ) {
F_6 ( V_56
L_13 ,
V_7 -> V_58 ) ;
goto V_57;
}
F_31 ( & V_55 ) ;
for ( V_44 = 0 ; V_44 < F_32 ( V_60 ) ; V_44 ++ ) {
V_2 = & V_60 [ V_44 ] ;
V_7 -> V_61 [ V_44 ] =
F_33 ( V_2 -> V_52 ,
V_2 -> V_62 ,
V_4 -> V_59 ,
V_4 ,
V_2 -> V_63 ) ;
if ( ! V_7 -> V_61 [ V_44 ] ) {
F_6 ( V_56
L_14 ,
V_7 -> V_58 , V_2 -> V_52 ) ;
goto V_57;
}
}
}
V_57:
return;
}
inline void
F_34 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < F_32 ( V_60 ) ; V_44 ++ ) {
if ( V_7 -> V_61 [ V_44 ] ) {
F_35 ( V_7 -> V_61 [ V_44 ] ) ;
V_7 -> V_61 [ V_44 ] = NULL ;
}
}
if ( V_4 -> V_59 ) {
F_35 ( V_4 -> V_59 ) ;
V_4 -> V_59 = NULL ;
F_36 ( & V_55 ) ;
}
if ( F_37 ( & V_55 ) == 0 ) {
F_35 ( V_54 ) ;
V_54 = NULL ;
}
}
