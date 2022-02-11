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
F_7 ( V_10 != V_11 ) ;
V_7 = F_8 ( V_10 , V_11 ) / sizeof( T_2 ) ;
if ( ! V_7 ) {
F_3 ( L_14 ) ;
return - V_12 ;
}
F_9 ( L_15 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
T_2 V_13 = F_10 ( V_8 [ V_3 ] ) ;
T_2 V_14 = F_10 ( V_9 [ V_3 ] ) ;
F_9 ( L_16 , V_13 , V_14 ) ;
V_15 [ V_3 ] . V_16 = V_14 * 1000 ;
V_15 [ V_3 ] . V_17 = V_13 ;
}
V_15 [ V_3 ] . V_16 = V_18 ;
V_19 . F_8 = V_4 ;
V_19 . V_20 = V_5 ;
V_19 . V_21 = V_6 ;
V_19 . V_7 = V_7 ;
return 0 ;
}
static unsigned int F_11 ( int V_22 )
{
int V_3 ;
V_3 = V_19 . V_20 - V_22 ;
F_12 ( V_3 >= V_19 . V_7 || V_3 < 0 ) ;
return V_15 [ V_3 ] . V_16 ;
}
static T_3 F_13 ( struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_17 ,
F_11 ( V_19 . V_21 ) ) ;
}
static inline unsigned long F_14 ( unsigned long V_26 )
{
switch ( V_26 ) {
case V_27 :
return F_15 ( V_27 ) ;
case V_28 :
return F_15 ( V_28 ) ;
case V_29 :
return F_15 ( V_29 ) ;
}
F_16 () ;
}
static inline void F_17 ( unsigned long V_26 , unsigned long V_30 )
{
switch ( V_26 ) {
case V_27 :
F_18 ( V_27 , V_30 ) ;
return;
case V_28 :
F_18 ( V_28 , V_30 ) ;
return;
}
F_16 () ;
}
static void F_19 ( void * V_31 )
{
unsigned long V_32 ;
T_4 V_33 ;
struct V_34 * V_35 = V_31 ;
V_32 = F_14 ( V_29 ) ;
V_33 = ( V_32 >> 48 ) & 0xFF ;
V_35 -> V_22 = V_33 ;
V_35 -> V_14 = F_11 ( V_35 -> V_22 ) ;
F_9 ( L_18 ,
F_20 () , V_32 , V_35 -> V_22 ,
V_35 -> V_14 ) ;
}
unsigned int F_21 ( unsigned int V_36 )
{
struct V_34 V_35 ;
F_22 ( F_23 ( V_36 ) , F_19 ,
& V_35 , 1 ) ;
return V_35 . V_14 ;
}
static void F_24 ( void * V_35 )
{
unsigned long V_30 ;
unsigned long V_37 =
( (struct V_34 * ) V_35 ) -> V_22 ;
V_30 = F_14 ( V_27 ) ;
V_30 = V_30 & 0x0000FFFFFFFFFFFFULL ;
V_37 = V_37 & 0xFF ;
V_30 = V_30 | ( V_37 << 56 ) | ( V_37 << 48 ) ;
F_9 ( L_19 ,
F_20 () , V_30 ) ;
F_17 ( V_27 , V_30 ) ;
}
static int F_25 ( struct V_23 * V_24 ,
unsigned int V_38 )
{
struct V_34 V_35 ;
V_35 . V_22 = V_15 [ V_38 ] . V_17 ;
F_22 ( V_24 -> V_39 , F_24 , & V_35 , 1 ) ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 )
{
int V_40 , V_3 ;
V_40 = F_27 ( V_24 -> V_36 ) ;
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ )
F_28 ( V_40 + V_3 , V_24 -> V_39 ) ;
return F_29 ( V_24 , V_15 ) ;
}
static int T_5 F_30 ( void )
{
int V_42 = 0 ;
V_42 = F_1 () ;
if ( V_42 ) {
F_5 ( L_20 ) ;
return V_42 ;
}
return F_31 ( & V_43 ) ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_43 ) ;
}
