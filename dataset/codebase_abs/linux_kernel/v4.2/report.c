static const void * F_1 ( const void * V_1 , T_1 V_2 )
{
T_2 V_3 = * ( T_2 * ) F_2 ( V_1 ) ;
const void * V_4 = V_1 ;
while ( ! V_3 && V_4 < V_1 + V_2 ) {
V_4 += V_5 ;
V_3 = * ( T_2 * ) F_2 ( V_4 ) ;
}
return V_4 ;
}
static void F_3 ( struct V_6 * V_7 )
{
const char * V_8 = L_1 ;
T_2 V_3 ;
V_7 -> V_4 = F_1 ( V_7 -> V_9 ,
V_7 -> V_10 ) ;
V_3 = * ( T_2 * ) F_2 ( V_7 -> V_4 ) ;
switch ( V_3 ) {
case V_11 :
case V_12 :
V_8 = L_2 ;
break;
case V_13 :
case V_14 :
case V_15 :
case 0 ... V_5 - 1 :
V_8 = L_3 ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_8 = L_4 ;
break;
}
F_4 ( L_5 ,
V_8 , ( void * ) V_7 -> V_20 ,
V_7 -> V_9 ) ;
F_4 ( L_6 ,
V_7 -> V_21 ? L_7 : L_8 ,
V_7 -> V_10 , V_22 -> V_23 , F_5 ( V_22 ) ) ;
}
static inline bool F_6 ( const void * V_1 )
{
return ( V_1 >= ( void * ) V_24 && V_1 < ( void * ) V_25 )
|| ( V_1 >= ( void * ) V_26
&& V_1 < ( void * ) V_27 ) ;
}
static inline bool F_7 ( const void * V_1 )
{
return V_1 >= ( void * ) & V_28 . V_29 &&
( V_1 <= ( void * ) & V_28 . V_29 +
sizeof( V_28 . V_29 ) ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
const void * V_1 = V_7 -> V_9 ;
if ( ( V_1 >= ( void * ) V_30 ) &&
( V_1 < V_31 ) ) {
struct V_32 * V_32 = F_9 ( V_1 ) ;
if ( F_10 ( V_32 ) ) {
void * V_33 ;
struct V_34 * V_35 = V_32 -> V_36 ;
void * V_37 ;
V_33 = F_11 ( V_35 , F_12 ( V_32 ) , V_1 ) ;
V_37 = F_12 ( V_32 ) +
V_32 -> V_38 * V_35 -> V_2 ;
if ( F_13 ( V_33 > V_37 ) )
V_33 = V_37 ;
F_14 ( V_35 , V_32 , V_33 ,
L_9 ) ;
return;
}
F_15 ( V_32 , L_9 ) ;
}
if ( F_6 ( V_1 ) ) {
if ( ! F_7 ( V_1 ) )
F_4 ( L_10 , V_1 ) ;
}
F_16 () ;
}
static bool F_17 ( const void * V_39 , const void * V_40 )
{
return ( V_39 <= V_40 ) && ( V_40 < V_39 + V_41 ) ;
}
static int F_18 ( const void * V_39 , const void * V_42 )
{
return 3 + ( V_43 / 8 ) * 2 + ( V_42 - V_39 ) * 2 +
( V_42 - V_39 ) / V_44 + 1 ;
}
static void F_19 ( const void * V_1 )
{
int V_45 ;
const void * V_42 = F_2 ( V_1 ) ;
const void * V_46 ;
V_46 = ( void * ) F_20 ( ( unsigned long ) V_42 ,
V_41 )
- V_47 * V_41 ;
F_4 ( L_11 ) ;
for ( V_45 = - V_47 ; V_45 <= V_47 ; V_45 ++ ) {
const void * V_48 = F_21 ( V_46 ) ;
char V_49 [ 4 + ( V_43 / 8 ) * 2 ] ;
snprintf ( V_49 , sizeof( V_49 ) ,
( V_45 == 0 ) ? L_12 : L_13 , V_48 ) ;
F_22 () ;
F_23 ( V_50 , V_49 ,
V_51 , V_41 , 1 ,
V_46 , V_41 , 0 ) ;
F_24 () ;
if ( F_17 ( V_46 , V_42 ) )
F_4 ( L_14 ,
F_18 ( V_46 , V_42 ) ,
'^' ) ;
V_46 += V_41 ;
}
}
void F_25 ( struct V_6 * V_7 )
{
unsigned long V_52 ;
F_26 ( & V_53 , V_52 ) ;
F_4 ( L_15
L_16 ) ;
F_3 ( V_7 ) ;
F_8 ( V_7 ) ;
F_19 ( V_7 -> V_4 ) ;
F_4 ( L_15
L_16 ) ;
F_27 ( & V_53 , V_52 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
unsigned long V_52 ;
F_26 ( & V_53 , V_52 ) ;
F_4 ( L_15
L_16 ) ;
F_4 ( L_17 ,
V_7 -> V_9 ) ;
F_4 ( L_6 ,
V_7 -> V_21 ? L_7 : L_8 ,
V_7 -> V_10 , V_22 -> V_23 , F_5 ( V_22 ) ) ;
F_16 () ;
F_4 ( L_15
L_16 ) ;
F_27 ( & V_53 , V_52 ) ;
}
void F_29 ( unsigned long V_1 , T_1 V_2 ,
bool V_21 , unsigned long V_20 )
{
struct V_6 V_7 ;
if ( F_30 ( ! F_31 () ) )
return;
V_7 . V_9 = ( void * ) V_1 ;
V_7 . V_10 = V_2 ;
V_7 . V_21 = V_21 ;
V_7 . V_20 = V_20 ;
F_25 ( & V_7 ) ;
}
void F_32 ( unsigned long V_1 , T_1 V_2 )
{
F_29 ( V_1 , V_2 , false , V_54 ) ;
}
void F_33 ( unsigned long V_1 , T_1 V_2 )
{
F_29 ( V_1 , V_2 , true , V_54 ) ;
}
