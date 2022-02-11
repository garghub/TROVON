static inline T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 -> V_3 + V_2 ) ;
}
static inline void F_3 ( struct V_1 * V_1 , T_1 V_4 , T_1 V_2 )
{
F_4 ( V_4 , V_1 -> V_3 + V_2 ) ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = V_8 ;
T_1 V_4 ;
while ( V_7 -- ) {
V_4 = F_1 ( V_1 , V_9 ) ;
if ( ( ( V_4 & V_5 ) == V_5 ) && ( ( V_4 & V_6 ) == 0 ) )
return 0 ;
F_6 ( 1 ) ;
}
return - V_10 ;
}
static int
F_7 ( struct V_1 * V_1 , T_2 V_11 , T_3 * V_12 , int V_13 )
{
T_1 V_14 = V_15 | ( ( V_11 & 0xff ) << 16 ) ;
int V_16 = 0 ;
if ( V_1 -> V_17 == V_18 ) {
T_1 V_19 = F_1 ( V_1 , V_20 ) ;
V_19 = F_8 ( V_19 , V_11 ) ;
F_3 ( V_1 , V_19 , V_20 ) ;
}
while ( V_13 ) {
V_16 = F_5 ( V_1 , V_21 , 0 ) ;
if ( V_16 )
goto V_22;
F_3 ( V_1 , V_14 , V_23 ) ;
V_16 = F_5 ( V_1 , V_24 , 0 ) ;
if ( V_16 )
goto V_22;
* V_12 ++ = F_1 ( V_1 , V_25 ) & 0xff ;
V_13 -- ;
}
V_22:
return V_16 ;
}
static int
F_9 ( struct V_1 * V_1 , T_2 V_11 , T_3 * V_12 , int V_13 )
{
int V_16 = 0 ;
if ( V_1 -> V_17 == V_18 ) {
T_1 V_19 = F_1 ( V_1 , V_20 ) ;
V_19 = F_8 ( V_19 , V_11 ) ;
F_3 ( V_1 , V_19 , V_20 ) ;
}
while ( V_13 ) {
V_16 = F_5 ( V_1 , V_21 , 0 ) ;
if ( V_16 )
goto V_22;
F_3 ( V_1 , ( ( V_11 & 0xff ) << 16 ) | * V_12 , V_23 ) ;
V_16 = F_5 ( V_1 , 0 , V_26 ) ;
if ( V_16 )
goto V_22;
V_12 ++ ;
V_13 -- ;
}
V_22:
return V_16 ;
}
static inline int
F_10 ( struct V_1 * V_1 , T_1 V_14 , T_3 * V_27 )
{
T_1 V_7 = V_8 ;
T_1 V_28 = 0 ;
F_3 ( V_1 , V_14 , V_29 ) ;
while ( V_7 -- ) {
V_28 = F_1 ( V_1 , V_30 ) ;
if ( V_28 & V_31 )
return - V_32 ;
if ( V_28 & V_33 ) {
if ( V_27 )
* V_27 = V_28 & 0xff ;
return 0 ;
}
F_6 ( 1 ) ;
}
return - V_10 ;
}
static int
F_11 ( struct V_1 * V_1 , T_2 V_11 , T_3 * V_12 , int V_13 )
{
T_1 V_14 ;
int V_16 = 0 ;
V_14 = V_34 | ( V_11 & V_35 ) << 8 ;
while ( V_13 ) {
V_16 = F_10 ( V_1 , V_14 , V_12 ) ;
if ( V_16 )
goto V_22;
V_12 ++ ;
V_13 -- ;
}
V_22:
return V_16 ;
}
static int
F_12 ( struct V_1 * V_1 , T_2 V_11 , T_3 * V_12 , int V_13 )
{
T_1 V_14 ;
int V_16 = 0 ;
while ( V_13 ) {
V_14 = ( V_11 & V_35 ) << 8 | * V_12 ;
V_16 = F_10 ( V_1 , V_14 , NULL ) ;
if ( V_16 )
goto V_22;
V_12 ++ ;
V_13 -- ;
}
V_22:
return V_16 ;
}
int F_13 ( struct V_36 * V_37 , T_2 V_11 , T_3 * V_12 , int V_13 )
{
struct V_1 * V_1 = F_14 ( V_37 ) ;
unsigned long V_38 ;
int V_16 ;
F_15 ( & V_1 -> V_39 , V_38 ) ;
V_16 = V_1 -> V_40 ( V_1 , V_11 , V_12 , V_13 ) ;
F_16 ( & V_1 -> V_39 , V_38 ) ;
return V_16 ;
}
int F_17 ( struct V_36 * V_37 , T_2 V_11 , T_3 * V_12 , int V_13 )
{
struct V_1 * V_1 = F_14 ( V_37 ) ;
unsigned long V_38 ;
int V_16 ;
F_15 ( & V_1 -> V_39 , V_38 ) ;
V_16 = V_1 -> V_41 ( V_1 , V_11 , V_12 , V_13 ) ;
F_16 ( & V_1 -> V_39 , V_38 ) ;
return V_16 ;
}
static int F_18 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_37 . V_46 ;
struct V_47 * V_48 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
const char * type ;
V_1 = F_19 ( sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_1 ) {
F_20 ( L_1 ) ;
return - V_50 ;
}
V_48 = F_21 ( V_43 , V_51 , 0 ) ;
if ( ! V_48 ) {
F_20 ( L_2 ) ;
V_16 = - V_52 ;
goto V_53;
}
V_1 -> V_3 = F_22 ( V_48 -> V_54 , F_23 ( V_48 ) ) ;
if ( ! V_1 -> V_3 ) {
F_20 ( L_3 , ( void * ) V_48 -> V_54 ) ;
V_16 = - V_52 ;
goto V_55;
}
F_24 ( V_43 , V_1 ) ;
type = F_25 ( V_45 , L_4 , NULL ) ;
if ( type == NULL ) {
F_20 ( L_5 ) ;
V_16 = - V_52 ;
goto V_56;
}
F_26 ( & V_43 -> V_37 , L_6 , type ) ;
if ( strcmp ( type , L_7 ) == 0 )
V_1 -> V_17 = V_57 ;
else if ( strcmp ( type , L_8 ) == 0 )
V_1 -> V_17 = V_18 ;
else if ( strcmp ( type , L_9 ) == 0 )
V_1 -> V_17 = V_58 ;
else {
F_20 ( L_10 ) ;
V_16 = - V_52 ;
goto V_56;
}
if ( V_1 -> V_17 == V_58 ) {
V_1 -> V_40 = F_11 ;
V_1 -> V_41 = F_12 ;
} else {
V_1 -> V_40 = F_7 ;
V_1 -> V_41 = F_9 ;
}
F_27 ( & V_1 -> V_39 ) ;
V_16 = F_28 ( V_45 , NULL , NULL , & V_43 -> V_37 ) ;
if ( V_16 )
goto V_56;
return 0 ;
V_56:
F_24 ( V_43 , NULL ) ;
F_29 ( V_1 -> V_3 ) ;
V_55:
V_53:
F_30 ( V_1 ) ;
return V_16 ;
}
static int F_31 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = F_32 ( V_43 ) ;
F_24 ( V_43 , NULL ) ;
F_29 ( V_1 -> V_3 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
return F_34 ( & V_59 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_59 ) ;
}
