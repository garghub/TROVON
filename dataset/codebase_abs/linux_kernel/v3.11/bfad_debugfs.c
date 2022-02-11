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
struct V_8 * V_9 = V_2 -> V_16 ;
return F_15 ( V_2 , V_27 , V_28 ,
V_9 -> V_14 ) ;
}
static T_2
F_16 ( struct V_2 * V_2 , char T_3 * V_29 ,
T_4 V_30 , T_1 * V_31 )
{
struct V_8 * V_9 = V_2 -> V_16 ;
if ( ! V_9 || ! V_9 -> V_12 )
return 0 ;
return F_17 ( V_29 , V_30 , V_31 ,
V_9 -> V_12 , V_9 -> V_14 ) ;
}
static T_5
F_18 ( struct V_32 * V_23 , T_6 V_27 , T_6 V_33 )
{
T_7 V_34 ;
V_34 = ( V_27 >> 15 ) & 0x7 ;
if ( V_34 == 0 ) {
if ( ( V_27 + ( V_33 << 2 ) ) > 0x8000 )
return V_35 ;
} else if ( V_34 == 0x1 ) {
if ( ( V_27 + ( V_33 << 2 ) ) > 0x10000 )
return V_35 ;
} else {
if ( ( V_27 + ( V_33 << 2 ) ) > F_19 ( & V_23 -> V_24 ) )
return V_35 ;
}
return V_25 ;
}
static T_2
F_20 ( struct V_2 * V_2 , char T_3 * V_29 ,
T_4 V_30 , T_1 * V_31 )
{
struct V_8 * V_36 = V_2 -> V_16 ;
struct V_3 * V_4 = (struct V_3 * ) V_36 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_2 V_19 ;
if ( ! V_7 -> V_37 )
return 0 ;
V_19 = F_17 ( V_29 , V_30 , V_31 ,
V_7 -> V_37 , V_7 -> V_38 ) ;
if ( ( * V_31 + V_30 ) >= V_7 -> V_38 ) {
F_5 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
V_7 -> V_38 = 0 ;
}
return V_19 ;
}
static T_2
F_21 ( struct V_2 * V_2 , const char T_3 * V_29 ,
T_4 V_30 , T_1 * V_39 )
{
struct V_8 * V_36 = V_2 -> V_16 ;
struct V_3 * V_4 = (struct V_3 * ) V_36 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_32 * V_23 = & V_7 -> V_23 ;
struct V_40 * V_24 = & V_23 -> V_24 ;
int V_41 , V_33 , V_19 , V_42 ;
T_6 * V_43 ;
void T_8 * V_44 , * V_45 ;
unsigned long V_18 ;
void * V_46 ;
V_46 = F_2 ( V_30 , V_10 ) ;
if ( ! V_46 ) {
F_6 ( V_20 L_5 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
if ( F_22 ( V_46 , ( void T_3 * ) V_29 , V_30 ) ) {
F_5 ( V_46 ) ;
return - V_11 ;
}
V_19 = sscanf ( V_46 , L_6 , & V_41 , & V_33 ) ;
if ( V_19 < 2 ) {
F_6 ( V_20
L_7 ,
V_7 -> V_21 , V_47 ) ;
F_5 ( V_46 ) ;
return - V_48 ;
}
F_5 ( V_46 ) ;
F_5 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
V_7 -> V_38 = 0 ;
V_7 -> V_37 = F_2 ( V_33 << 2 , V_10 ) ;
if ( ! V_7 -> V_37 ) {
F_6 ( V_20 L_8 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
V_7 -> V_38 = V_33 << 2 ;
V_44 = F_23 ( V_24 ) ;
V_41 &= F_19 ( V_24 ) ;
V_19 = F_18 ( V_23 , V_41 , V_33 ) ;
if ( V_19 ) {
F_6 ( V_20 L_9 ,
V_7 -> V_21 ) ;
F_5 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
V_7 -> V_38 = 0 ;
return - V_48 ;
}
V_45 = V_44 + V_41 ;
V_43 = ( T_6 * ) V_7 -> V_37 ;
F_7 ( & V_7 -> V_22 , V_18 ) ;
for ( V_42 = 0 ; V_42 < V_33 ; V_42 ++ ) {
* V_43 = F_24 ( V_45 ) ;
V_43 ++ ;
V_45 += sizeof( T_6 ) ;
}
F_9 ( & V_7 -> V_22 , V_18 ) ;
return V_30 ;
}
static T_2
F_25 ( struct V_2 * V_2 , const char T_3 * V_29 ,
T_4 V_30 , T_1 * V_39 )
{
struct V_8 * V_9 = V_2 -> V_16 ;
struct V_3 * V_4 = (struct V_3 * ) V_9 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_32 * V_23 = & V_7 -> V_23 ;
struct V_40 * V_24 = & V_23 -> V_24 ;
int V_41 , V_49 , V_19 ;
void T_8 * V_45 ;
unsigned long V_18 ;
void * V_46 ;
V_46 = F_2 ( V_30 , V_10 ) ;
if ( ! V_46 ) {
F_6 ( V_20 L_5 ,
V_7 -> V_21 ) ;
return - V_11 ;
}
if ( F_22 ( V_46 , ( void T_3 * ) V_29 , V_30 ) ) {
F_5 ( V_46 ) ;
return - V_11 ;
}
V_19 = sscanf ( V_46 , L_6 , & V_41 , & V_49 ) ;
if ( V_19 < 2 ) {
F_6 ( V_20
L_7 ,
V_7 -> V_21 , V_47 ) ;
F_5 ( V_46 ) ;
return - V_48 ;
}
F_5 ( V_46 ) ;
V_41 &= F_19 ( V_24 ) ;
V_19 = F_18 ( V_23 , V_41 , 1 ) ;
if ( V_19 ) {
F_6 ( V_20
L_9 ,
V_7 -> V_21 ) ;
return - V_48 ;
}
V_45 = ( F_23 ( V_24 ) ) + V_41 ;
F_7 ( & V_7 -> V_22 , V_18 ) ;
F_26 ( V_49 , V_45 ) ;
F_9 ( & V_7 -> V_22 , V_18 ) ;
return V_30 ;
}
static int
F_27 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_16 ;
if ( ! V_9 )
return 0 ;
V_2 -> V_16 = NULL ;
F_5 ( V_9 ) ;
return 0 ;
}
static int
F_28 ( struct V_1 * V_1 , struct V_2 * V_2 )
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
F_29 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
const struct V_50 * V_2 ;
char V_51 [ 64 ] ;
int V_42 ;
if ( ! V_52 )
return;
if ( ! V_53 ) {
V_53 = F_30 ( L_10 , NULL ) ;
F_31 ( & V_54 , 0 ) ;
if ( ! V_53 ) {
F_6 ( V_55
L_11 ) ;
goto V_56;
}
}
snprintf ( V_51 , sizeof( V_51 ) , L_12 , V_7 -> V_57 ) ;
if ( ! V_4 -> V_58 ) {
V_4 -> V_58 =
F_30 ( V_51 , V_53 ) ;
if ( ! V_4 -> V_58 ) {
F_6 ( V_55
L_13 ,
V_7 -> V_57 ) ;
goto V_56;
}
F_32 ( & V_54 ) ;
for ( V_42 = 0 ; V_42 < F_33 ( V_59 ) ; V_42 ++ ) {
V_2 = & V_59 [ V_42 ] ;
V_7 -> V_60 [ V_42 ] =
F_34 ( V_2 -> V_51 ,
V_2 -> V_61 ,
V_4 -> V_58 ,
V_4 ,
V_2 -> V_62 ) ;
if ( ! V_7 -> V_60 [ V_42 ] ) {
F_6 ( V_55
L_14 ,
V_7 -> V_57 , V_2 -> V_51 ) ;
goto V_56;
}
}
}
V_56:
return;
}
inline void
F_35 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_33 ( V_59 ) ; V_42 ++ ) {
if ( V_7 -> V_60 [ V_42 ] ) {
F_36 ( V_7 -> V_60 [ V_42 ] ) ;
V_7 -> V_60 [ V_42 ] = NULL ;
}
}
if ( V_4 -> V_58 ) {
F_36 ( V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
F_37 ( & V_54 ) ;
}
if ( F_38 ( & V_54 ) == 0 ) {
F_36 ( V_53 ) ;
V_53 = NULL ;
}
}
