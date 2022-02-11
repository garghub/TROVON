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
T_2 * V_9 ;
V_7 -> V_4 = F_1 ( V_7 -> V_10 ,
V_7 -> V_11 ) ;
V_9 = ( T_2 * ) F_2 ( V_7 -> V_4 ) ;
if ( * V_9 > 0 && * V_9 <= V_5 - 1 )
V_9 ++ ;
switch ( * V_9 ) {
case 0 ... V_5 - 1 :
V_8 = L_2 ;
break;
case V_12 :
case V_13 :
V_8 = L_3 ;
break;
case V_14 :
V_8 = L_4 ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_8 = L_5 ;
break;
case V_19 :
case V_20 :
V_8 = L_6 ;
break;
}
F_4 ( L_7 ,
V_8 , ( void * ) V_7 -> V_21 ,
V_7 -> V_10 ) ;
F_4 ( L_8 ,
V_7 -> V_22 ? L_9 : L_10 ,
V_7 -> V_11 , V_23 -> V_24 , F_5 ( V_23 ) ) ;
}
static inline bool F_6 ( const void * V_1 )
{
if ( V_1 >= ( void * ) V_25 && V_1 < ( void * ) V_26 )
return true ;
if ( F_7 ( ( unsigned long ) V_1 ) )
return true ;
return false ;
}
static inline bool F_8 ( const void * V_1 )
{
return V_1 >= ( void * ) & V_27 . V_28 &&
( V_1 <= ( void * ) & V_27 . V_28 +
sizeof( V_27 . V_28 ) ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
const void * V_1 = V_7 -> V_10 ;
if ( ( V_1 >= ( void * ) V_29 ) &&
( V_1 < V_30 ) ) {
struct V_31 * V_31 = F_10 ( V_1 ) ;
if ( F_11 ( V_31 ) ) {
void * V_32 ;
struct V_33 * V_34 = V_31 -> V_35 ;
void * V_36 ;
V_32 = F_12 ( V_34 , F_13 ( V_31 ) , V_1 ) ;
V_36 = F_13 ( V_31 ) +
V_31 -> V_37 * V_34 -> V_2 ;
if ( F_14 ( V_32 > V_36 ) )
V_32 = V_36 ;
F_15 ( V_34 , V_31 , V_32 ,
L_11 ) ;
return;
}
F_16 ( V_31 , L_11 ) ;
}
if ( F_6 ( V_1 ) ) {
if ( ! F_8 ( V_1 ) )
F_4 ( L_12 , V_1 ) ;
}
F_17 () ;
}
static bool F_18 ( const void * V_38 , const void * V_39 )
{
return ( V_38 <= V_39 ) && ( V_39 < V_38 + V_40 ) ;
}
static int F_19 ( const void * V_38 , const void * V_41 )
{
return 3 + ( V_42 / 8 ) * 2 + ( V_41 - V_38 ) * 2 +
( V_41 - V_38 ) / V_43 + 1 ;
}
static void F_20 ( const void * V_1 )
{
int V_44 ;
const void * V_41 = F_2 ( V_1 ) ;
const void * V_45 ;
V_45 = ( void * ) F_21 ( ( unsigned long ) V_41 ,
V_40 )
- V_46 * V_40 ;
F_4 ( L_13 ) ;
for ( V_44 = - V_46 ; V_44 <= V_46 ; V_44 ++ ) {
const void * V_47 = F_22 ( V_45 ) ;
char V_48 [ 4 + ( V_42 / 8 ) * 2 ] ;
char V_49 [ V_40 ] ;
snprintf ( V_48 , sizeof( V_48 ) ,
( V_44 == 0 ) ? L_14 : L_15 , V_47 ) ;
memcpy ( V_49 , V_45 , V_40 ) ;
F_23 ( V_50 , V_48 ,
V_51 , V_40 , 1 ,
V_49 , V_40 , 0 ) ;
if ( F_18 ( V_45 , V_41 ) )
F_4 ( L_16 ,
F_19 ( V_45 , V_41 ) ,
'^' ) ;
V_45 += V_40 ;
}
}
static void F_24 ( struct V_6 * V_7 )
{
unsigned long V_52 ;
const char * V_8 ;
F_25 () ;
F_26 ( & V_53 , V_52 ) ;
F_4 ( L_17
L_18 ) ;
if ( V_7 -> V_10 <
F_22 ( ( void * ) V_54 ) ) {
if ( ( unsigned long ) V_7 -> V_10 < V_55 )
V_8 = L_19 ;
else if ( ( unsigned long ) V_7 -> V_10 < V_56 )
V_8 = L_20 ;
else
V_8 = L_21 ;
F_4 ( L_22 ,
V_8 , V_7 -> V_10 ) ;
F_4 ( L_8 ,
V_7 -> V_22 ? L_9 : L_10 ,
V_7 -> V_11 , V_23 -> V_24 ,
F_5 ( V_23 ) ) ;
F_17 () ;
} else {
F_3 ( V_7 ) ;
F_9 ( V_7 ) ;
F_20 ( V_7 -> V_4 ) ;
}
F_4 ( L_17
L_18 ) ;
F_27 ( V_57 , V_58 ) ;
F_28 ( & V_53 , V_52 ) ;
F_29 () ;
}
void F_30 ( unsigned long V_1 , T_1 V_2 ,
bool V_22 , unsigned long V_21 )
{
struct V_6 V_7 ;
if ( F_31 ( ! F_32 () ) )
return;
V_7 . V_10 = ( void * ) V_1 ;
V_7 . V_11 = V_2 ;
V_7 . V_22 = V_22 ;
V_7 . V_21 = V_21 ;
F_24 ( & V_7 ) ;
}
void F_33 ( unsigned long V_1 , T_1 V_2 )
{
F_30 ( V_1 , V_2 , false , V_59 ) ;
}
void F_34 ( unsigned long V_1 , T_1 V_2 )
{
F_30 ( V_1 , V_2 , true , V_59 ) ;
}
