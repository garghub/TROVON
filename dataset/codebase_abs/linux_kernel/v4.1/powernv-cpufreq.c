static int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 , V_4 , V_5 , V_6 , V_7 = 0 ;
const T_1 * V_8 , * V_9 ;
T_2 V_10 , V_11 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return - V_12 ;
}
if ( F_4 ( V_2 , L_3 , & V_4 ) ) {
F_3 ( L_4 ) ;
return - V_12 ;
}
if ( F_4 ( V_2 , L_5 , & V_5 ) ) {
F_3 ( L_6 ) ;
return - V_12 ;
}
if ( F_4 ( V_2 , L_7 ,
& V_6 ) ) {
F_3 ( L_8 ) ;
return - V_12 ;
}
F_5 ( L_9 , V_4 ,
V_6 , V_5 ) ;
V_8 = F_6 ( V_2 , L_10 , & V_10 ) ;
if ( ! V_8 ) {
F_3 ( L_11 ) ;
return - V_12 ;
}
V_9 = F_6 ( V_2 , L_12 ,
& V_11 ) ;
if ( ! V_9 ) {
F_3 ( L_13 ) ;
return - V_12 ;
}
if ( V_10 != V_11 ) {
F_3 ( L_14
L_15 ) ;
}
V_7 = F_7 ( V_10 , V_11 ) / sizeof( T_2 ) ;
if ( ! V_7 ) {
F_3 ( L_16 ) ;
return - V_12 ;
}
F_8 ( L_17 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
T_2 V_13 = F_9 ( V_8 [ V_3 ] ) ;
T_2 V_14 = F_9 ( V_9 [ V_3 ] ) ;
F_8 ( L_18 , V_13 , V_14 ) ;
V_15 [ V_3 ] . V_16 = V_14 * 1000 ;
V_15 [ V_3 ] . V_17 = V_13 ;
}
V_15 [ V_3 ] . V_16 = V_18 ;
V_19 . F_7 = V_4 ;
V_19 . V_20 = V_5 ;
V_19 . V_21 = V_6 ;
V_19 . V_7 = V_7 ;
return 0 ;
}
static unsigned int F_10 ( int V_22 )
{
int V_3 ;
V_3 = V_19 . V_20 - V_22 ;
if ( V_3 >= V_19 . V_7 || V_3 < 0 ) {
F_3 ( L_19
L_20 ,
V_22 , V_19 . V_21 ) ;
V_3 = V_19 . V_20 - V_19 . V_21 ;
}
return V_15 [ V_3 ] . V_16 ;
}
static T_3 F_11 ( struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_21 ,
F_10 ( V_19 . V_21 ) ) ;
}
static inline unsigned long F_12 ( unsigned long V_26 )
{
switch ( V_26 ) {
case V_27 :
return F_13 ( V_27 ) ;
case V_28 :
return F_13 ( V_28 ) ;
case V_29 :
return F_13 ( V_29 ) ;
}
F_14 () ;
}
static inline void F_15 ( unsigned long V_26 , unsigned long V_30 )
{
switch ( V_26 ) {
case V_27 :
F_16 ( V_27 , V_30 ) ;
return;
case V_28 :
F_16 ( V_28 , V_30 ) ;
return;
}
F_14 () ;
}
static void F_17 ( void * V_31 )
{
unsigned long V_32 ;
T_4 V_33 ;
struct V_34 * V_35 = V_31 ;
V_32 = F_12 ( V_29 ) ;
V_33 = ( V_32 >> 48 ) & 0xFF ;
V_35 -> V_22 = V_33 ;
V_35 -> V_14 = F_10 ( V_35 -> V_22 ) ;
F_8 ( L_22 ,
F_18 () , V_32 , V_35 -> V_22 ,
V_35 -> V_14 ) ;
}
static unsigned int F_19 ( unsigned int V_36 )
{
struct V_34 V_35 ;
F_20 ( F_21 ( V_36 ) , F_17 ,
& V_35 , 1 ) ;
return V_35 . V_14 ;
}
static void F_22 ( void * V_35 )
{
unsigned long V_30 ;
unsigned long V_37 =
( (struct V_34 * ) V_35 ) -> V_22 ;
V_30 = F_12 ( V_27 ) ;
V_30 = V_30 & 0x0000FFFFFFFFFFFFULL ;
V_37 = V_37 & 0xFF ;
V_30 = V_30 | ( V_37 << 56 ) | ( V_37 << 48 ) ;
F_8 ( L_23 ,
F_18 () , V_30 ) ;
F_15 ( V_27 , V_30 ) ;
}
static inline unsigned int F_23 ( void )
{
return V_19 . V_20 - V_19 . V_21 ;
}
static void F_24 ( unsigned int V_36 )
{
unsigned long V_38 ;
int V_39 , V_40 ;
V_38 = F_12 ( V_29 ) ;
V_39 = ( T_4 ) F_25 ( V_38 ) ;
if ( V_39 != V_19 . V_20 ) {
V_41 = true ;
F_5 ( L_24 , V_36 , V_39 ) ;
F_5 ( L_25 ) ;
}
V_40 = ( T_4 ) F_26 ( V_38 ) ;
if ( ( V_40 < V_19 . F_7 ) ||
( V_38 & V_42 ) ) {
V_41 = true ;
F_5 ( L_26 ) ;
}
if ( V_38 & V_43 ) {
V_41 = true ;
F_5 ( L_27 ) ;
}
if ( V_41 ) {
F_5 ( L_28 , V_38 ) ;
F_27 ( L_29 ) ;
}
}
static int F_28 ( struct V_23 * V_24 ,
unsigned int V_44 )
{
struct V_34 V_35 ;
if ( F_29 ( V_45 ) && V_44 != F_23 () )
return 0 ;
if ( ! V_41 )
F_24 ( F_30 () ) ;
V_35 . V_22 = V_15 [ V_44 ] . V_17 ;
F_20 ( V_24 -> V_46 , F_22 , & V_35 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 )
{
int V_47 , V_3 ;
V_47 = F_32 ( V_24 -> V_36 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
F_33 ( V_47 + V_3 , V_24 -> V_46 ) ;
return F_34 ( V_24 , V_15 ) ;
}
static int F_35 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
int V_36 ;
struct V_23 V_53 ;
V_45 = true ;
F_36 (cpu) {
F_37 ( & V_53 , V_36 ) ;
F_28 ( & V_53 , F_23 () ) ;
}
return V_54 ;
}
static void F_38 ( struct V_23 * V_24 )
{
struct V_34 V_35 ;
V_35 . V_22 = V_19 . F_7 ;
F_39 ( V_24 -> V_36 , F_22 , & V_35 , 1 ) ;
}
static int T_5 F_40 ( void )
{
int V_55 = 0 ;
if ( ! F_41 ( V_56 ) )
return - V_12 ;
V_55 = F_1 () ;
if ( V_55 ) {
F_5 ( L_30 ) ;
return V_55 ;
}
F_42 ( & V_57 ) ;
return F_43 ( & V_58 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_57 ) ;
F_46 ( & V_58 ) ;
}
