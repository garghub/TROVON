static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( V_4 -> V_5 ) ;
if ( V_4 -> V_5 == V_4 -> V_6 )
* V_4 = V_2 -> V_7 [ -- V_2 -> V_8 ] ;
}
static bool F_3 ( struct V_3 V_9 ,
struct V_3 V_10 )
{
T_1 V_11 = F_4 ( V_9 . V_5 , V_10 . V_5 ) ;
return V_11 ? V_11 > 0 : V_9 . V_5 < V_10 . V_5 ;
}
static bool F_5 ( struct V_12 * V_11 , const struct V_13 * V_5 )
{
unsigned V_4 ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ )
if ( F_7 ( V_11 , V_5 , V_4 ) ) {
struct V_14 * V_15 = F_8 ( V_11 , V_5 , V_4 ) ;
T_2 V_16 = F_9 ( V_11 , V_5 , V_4 ) ;
T_2 V_10 = F_10 ( V_11 , F_11 ( V_5 , V_4 ) ) ;
if ( F_12 ( V_5 ) + V_10 > V_11 -> V_17 . V_18 ||
V_16 < V_15 -> V_17 . V_19 ||
V_16 >= V_15 -> V_17 . V_20 )
return true ;
}
return false ;
}
static const char * F_13 ( struct V_12 * V_11 , const struct V_13 * V_5 )
{
unsigned V_4 ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ )
if ( F_7 ( V_11 , V_5 , V_4 ) ) {
struct V_14 * V_15 = F_8 ( V_11 , V_5 , V_4 ) ;
T_2 V_16 = F_9 ( V_11 , V_5 , V_4 ) ;
T_2 V_10 = F_10 ( V_11 , F_11 ( V_5 , V_4 ) ) ;
if ( F_12 ( V_5 ) + V_10 > V_11 -> V_17 . V_18 )
return L_1 ;
if ( V_16 < V_15 -> V_17 . V_19 )
return L_2 ;
if ( V_16 >= V_15 -> V_17 . V_20 )
return L_3 ;
if ( F_14 ( V_11 , V_5 , V_4 ) )
return L_4 ;
}
if ( ! F_4 ( V_5 , & V_21 ) )
return L_5 ;
if ( ! F_6 ( V_5 ) )
return L_6 ;
if ( ! F_12 ( V_5 ) )
return L_7 ;
return L_8 ;
}
void F_15 ( char * V_22 , T_2 V_23 , const struct V_13 * V_5 )
{
unsigned V_4 = 0 ;
char * V_24 = V_22 , * V_6 = V_22 + V_23 ;
#define F_16 ( ... ) (out += scnprintf(out, end - out, __VA_ARGS__))
F_16 ( L_9 , F_17 ( V_5 ) , F_18 ( V_5 ) , F_12 ( V_5 ) ) ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ ) {
if ( V_4 )
F_16 ( L_10 ) ;
if ( F_19 ( V_5 , V_4 ) == V_25 )
F_16 ( L_11 ) ;
else
F_16 ( L_12 , F_19 ( V_5 , V_4 ) ,
F_11 ( V_5 , V_4 ) , F_20 ( V_5 , V_4 ) ) ;
}
F_16 ( L_13 ) ;
if ( F_21 ( V_5 ) )
F_16 ( L_14 ) ;
if ( F_22 ( V_5 ) )
F_16 ( L_15 , F_22 ( V_5 ) , V_5 -> V_26 [ 1 ] ) ;
#undef F_16
}
static void F_23 ( struct V_27 * V_28 , const struct V_13 * V_5 )
{
struct V_29 * V_30 = F_24 ( V_28 , struct V_29 , V_28 ) ;
unsigned V_31 ;
char V_22 [ 80 ] ;
F_15 ( V_22 , sizeof( V_22 ) , V_5 ) ;
F_25 ( L_16 , V_22 ) ;
for ( V_31 = 0 ; V_31 < F_6 ( V_5 ) ; V_31 ++ ) {
T_2 V_32 = F_9 ( V_30 -> V_11 , V_5 , V_31 ) ;
F_25 ( L_17 , V_32 ) ;
if ( V_32 >= V_30 -> V_11 -> V_17 . V_19 && V_32 < V_30 -> V_11 -> V_17 . V_20 )
F_25 ( L_18 ,
F_26 ( V_30 -> V_11 , V_5 , V_31 ) -> V_33 ) ;
}
F_25 ( L_19 , F_13 ( V_30 -> V_11 , V_5 ) ) ;
}
bool F_27 ( struct V_12 * V_11 , const struct V_13 * V_5 )
{
char V_22 [ 80 ] ;
if ( ! F_6 ( V_5 ) || ! F_12 ( V_5 ) || F_21 ( V_5 ) )
goto V_34;
if ( F_5 ( V_11 , V_5 ) )
goto V_34;
return false ;
V_34:
F_15 ( V_22 , sizeof( V_22 ) , V_5 ) ;
F_28 ( V_11 , L_20 , V_22 , F_13 ( V_11 , V_5 ) ) ;
return true ;
}
static bool F_29 ( struct V_27 * V_35 , const struct V_13 * V_5 )
{
struct V_29 * V_30 = F_24 ( V_35 , struct V_29 , V_28 ) ;
return F_27 ( V_30 -> V_11 , V_5 ) ;
}
static bool F_30 ( struct V_29 * V_30 , const struct V_13 * V_5 )
{
unsigned V_4 ;
char V_22 [ 80 ] ;
struct V_16 * V_36 ;
if ( F_31 ( & V_30 -> V_11 -> V_37 ) ) {
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ )
if ( F_7 ( V_30 -> V_11 , V_5 , V_4 ) ) {
V_36 = F_26 ( V_30 -> V_11 , V_5 , V_4 ) ;
if ( F_21 ( V_5 ) ||
V_36 -> V_33 != V_38 ||
( V_30 -> V_11 -> V_39 &&
F_32 ( V_36 ) != V_40 ) )
goto V_41;
}
F_33 ( & V_30 -> V_11 -> V_37 ) ;
}
return false ;
V_41:
F_33 ( & V_30 -> V_11 -> V_37 ) ;
F_15 ( V_22 , sizeof( V_22 ) , V_5 ) ;
F_34 ( V_30 ,
L_21 ,
V_22 , F_9 ( V_30 -> V_11 , V_5 , V_4 ) , F_35 ( & V_36 -> V_42 ) ,
V_36 -> V_33 , V_36 -> V_43 , V_36 -> V_44 , F_32 ( V_36 ) , V_36 -> V_45 ) ;
return true ;
}
static bool F_36 ( struct V_27 * V_35 , const struct V_13 * V_5 )
{
struct V_29 * V_30 = F_24 ( V_35 , struct V_29 , V_28 ) ;
unsigned V_4 ;
if ( ! F_4 ( V_5 , & V_21 ) ||
! F_6 ( V_5 ) ||
F_37 ( V_35 , V_5 ) )
return true ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ )
if ( ! F_7 ( V_30 -> V_11 , V_5 , V_4 ) ||
F_14 ( V_30 -> V_11 , V_5 , V_4 ) )
return true ;
if ( F_38 ( V_30 -> V_11 ) &&
F_30 ( V_30 , V_5 ) )
return true ;
return false ;
}
static bool F_39 ( struct V_27 * V_35 ,
struct V_13 * V_46 ,
struct V_1 * V_2 ,
struct V_13 * V_47 )
{
struct V_29 * V_30 = F_24 ( V_35 , struct V_29 , V_28 ) ;
if ( ! F_40 ( V_46 ) )
F_41 ( V_30 ) -> V_48 ++ ;
return false ;
}
static bool F_42 ( struct V_3 V_9 ,
struct V_3 V_10 )
{
T_1 V_11 = F_4 ( & F_43 ( V_9 . V_5 ) , & F_43 ( V_10 . V_5 ) ) ;
return V_11 ? V_11 > 0 : V_9 . V_5 < V_10 . V_5 ;
}
static struct V_13 * F_44 ( struct V_1 * V_2 ,
struct V_13 * V_49 )
{
while ( V_2 -> V_8 > 1 ) {
struct V_3 * V_50 = V_2 -> V_7 , * V_4 = V_50 + 1 ;
if ( V_2 -> V_8 > 2 &&
F_42 ( V_4 [ 0 ] , V_4 [ 1 ] ) )
V_4 ++ ;
if ( F_4 ( V_50 -> V_5 , & F_43 ( V_4 -> V_5 ) ) <= 0 )
break;
if ( ! F_12 ( V_4 -> V_5 ) ) {
F_1 ( V_2 , V_4 ) ;
F_45 ( V_2 , V_4 - V_50 , F_42 ) ;
continue;
}
if ( V_50 -> V_5 > V_4 -> V_5 ) {
if ( F_4 ( V_50 -> V_5 , V_4 -> V_5 ) >= 0 )
F_1 ( V_2 , V_4 ) ;
else
F_46 ( V_50 -> V_5 , V_4 -> V_5 ) ;
F_45 ( V_2 , V_4 - V_50 , F_42 ) ;
} else {
F_47 ( ! F_4 ( & F_43 ( V_50 -> V_5 ) , & F_43 ( V_4 -> V_5 ) ) ) ;
if ( F_4 ( V_4 -> V_5 , V_50 -> V_5 ) < 0 ) {
F_48 ( V_49 , V_50 -> V_5 ) ;
F_49 ( & F_43 ( V_4 -> V_5 ) , V_49 ) ;
F_46 ( V_4 -> V_5 , V_50 -> V_5 ) ;
F_45 ( V_2 , 0 , F_42 ) ;
return V_49 ;
} else {
F_49 ( & F_43 ( V_4 -> V_5 ) , V_50 -> V_5 ) ;
}
}
}
return NULL ;
}
void F_50 ( struct V_13 * V_5 , T_3 V_51 , int V_52 )
{
if ( F_21 ( V_5 ) )
F_51 ( V_11 , F_17 ( V_5 ) ,
V_51 , - V_52 ) ;
}
static bool F_52 ( struct V_27 * V_35 , const struct V_13 * V_5 )
{
struct V_29 * V_30 = F_24 ( V_35 , struct V_29 , V_28 ) ;
char V_22 [ 80 ] ;
if ( ! F_12 ( V_5 ) )
return true ;
if ( F_12 ( V_5 ) > F_40 ( V_5 ) )
goto V_34;
if ( F_5 ( V_30 -> V_11 , V_5 ) )
goto V_34;
return false ;
V_34:
F_15 ( V_22 , sizeof( V_22 ) , V_5 ) ;
F_28 ( V_30 -> V_11 , L_22 , V_22 , F_13 ( V_30 -> V_11 , V_5 ) ) ;
return true ;
}
static bool F_53 ( struct V_29 * V_30 , const struct V_13 * V_5 ,
unsigned V_26 )
{
struct V_16 * V_36 = F_26 ( V_30 -> V_11 , V_5 , V_26 ) ;
char V_22 [ 80 ] ;
if ( F_31 ( & V_30 -> V_11 -> V_37 ) ) {
if ( V_30 -> V_11 -> V_39 &&
( ( F_32 ( V_36 ) != V_53 &&
F_21 ( V_5 ) ) ||
F_32 ( V_36 ) == V_40 ) )
goto V_41;
if ( V_36 -> V_33 == V_38 )
goto V_41;
F_33 ( & V_30 -> V_11 -> V_37 ) ;
}
return false ;
V_41:
F_33 ( & V_30 -> V_11 -> V_37 ) ;
F_15 ( V_22 , sizeof( V_22 ) , V_5 ) ;
F_34 ( V_30 ,
L_23 ,
V_22 , F_9 ( V_30 -> V_11 , V_5 , V_26 ) , F_35 ( & V_36 -> V_42 ) ,
V_36 -> V_33 , V_36 -> V_43 , V_36 -> V_44 , F_32 ( V_36 ) , V_36 -> V_45 ) ;
return true ;
}
static bool F_54 ( struct V_27 * V_35 , const struct V_13 * V_5 )
{
struct V_29 * V_30 = F_24 ( V_35 , struct V_29 , V_28 ) ;
struct V_16 * V_36 ;
unsigned V_4 , V_54 ;
if ( ! F_6 ( V_5 ) ||
F_52 ( V_35 , V_5 ) )
return true ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ )
if ( ! F_7 ( V_30 -> V_11 , V_5 , V_4 ) )
return true ;
if ( ! F_38 ( V_30 -> V_11 ) && F_21 ( V_5 ) )
return false ;
for ( V_4 = 0 ; V_4 < F_6 ( V_5 ) ; V_4 ++ ) {
V_36 = F_26 ( V_30 -> V_11 , V_5 , V_4 ) ;
V_54 = F_14 ( V_30 -> V_11 , V_5 , V_4 ) ;
F_55 ( V_54 > 96 , V_30 ,
L_24 ,
V_54 , V_30 -> V_11 -> V_55 ) ;
F_55 ( V_54 && F_21 ( V_5 ) && F_12 ( V_5 ) ,
V_30 , L_25 ) ;
if ( V_54 )
return true ;
if ( F_38 ( V_30 -> V_11 ) &&
F_53 ( V_30 , V_5 , V_4 ) )
return true ;
}
return false ;
}
static T_3 F_56 ( struct V_13 * V_9 , struct V_13 * V_10 )
{
return ( V_9 -> V_26 [ F_6 ( V_9 ) ] + V_10 -> V_26 [ F_6 ( V_10 ) ] ) &
~ ( ( T_3 ) 1 << 63 ) ;
}
static bool F_57 ( struct V_27 * V_35 , struct V_13 * V_9 , struct V_13 * V_10 )
{
struct V_29 * V_30 = F_24 ( V_35 , struct V_29 , V_28 ) ;
unsigned V_4 ;
if ( F_58 ( V_30 -> V_11 ) )
return false ;
for ( V_4 = 0 ; V_4 < F_6 ( V_9 ) ; V_4 ++ )
if ( V_9 -> V_26 [ V_4 ] + F_59 ( 0 , F_12 ( V_9 ) , 0 ) != V_10 -> V_26 [ V_4 ] ||
F_9 ( V_30 -> V_11 , V_9 , V_4 ) != F_9 ( V_30 -> V_11 , V_10 , V_4 ) )
return false ;
if ( F_12 ( V_9 ) + F_12 ( V_10 ) > V_56 ) {
F_60 ( V_9 , F_40 ( V_9 ) + V_56 - F_12 ( V_9 ) ) ;
F_61 ( V_9 , V_56 ) ;
F_46 ( V_9 , V_10 ) ;
return false ;
}
if ( F_22 ( V_9 ) ) {
if ( F_22 ( V_10 ) )
V_9 -> V_26 [ F_6 ( V_9 ) ] = F_56 ( V_9 , V_10 ) ;
else
F_62 ( V_9 , 0 ) ;
}
F_60 ( V_9 , F_40 ( V_9 ) + F_12 ( V_10 ) ) ;
F_61 ( V_9 , F_12 ( V_9 ) + F_12 ( V_10 ) ) ;
return true ;
}
