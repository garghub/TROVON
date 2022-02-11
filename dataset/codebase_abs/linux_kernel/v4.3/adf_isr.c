static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = 1 ;
if ( ! V_2 -> V_10 . V_11 ) {
int V_12 ;
V_9 += V_7 -> V_13 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ )
V_4 -> V_14 . V_15 [ V_12 ] . V_16 = V_12 ;
} else {
V_4 -> V_14 . V_15 [ 0 ] . V_16 =
V_7 -> V_13 ;
}
if ( F_2 ( V_4 -> V_17 ,
V_4 -> V_14 . V_15 ,
V_9 ) ) {
F_3 ( & F_4 ( V_2 ) , L_1 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_6 ( V_4 -> V_17 ) ;
}
static T_2 F_7 ( int V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
F_8 ( V_22 -> V_23 , V_22 -> V_24 , 0 ) ;
F_9 ( & V_22 -> V_25 ) ;
return V_26 ;
}
static T_2 F_10 ( int V_19 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
#ifdef F_11
if ( V_2 -> V_10 . V_11 ) {
void T_3 * V_28 =
( & F_12 ( V_2 ) [ V_29 ] ) -> V_30 ;
T_1 V_31 ;
V_31 = ( ( F_13 ( V_28 , V_32 ) &
0x0000FFFF ) << 16 ) |
( ( F_13 ( V_28 , V_33 ) &
0x01FFFE00 ) >> 9 ) ;
if ( V_31 ) {
struct V_34 * V_11 ;
bool V_35 = false ;
int V_12 ;
F_14 ( V_2 , V_31 ) ;
F_15 (i, (const unsigned long *)&vf_mask,
(sizeof(vf_mask) * BITS_PER_BYTE)) {
V_11 = V_2 -> V_10 . V_11 + V_12 ;
if ( ! F_16 ( & V_11 -> V_36 ) ) {
F_17 ( & F_4 ( V_2 ) ,
L_2 ,
V_11 -> V_37 + 1 ) ;
continue;
}
F_9 ( & V_11 -> V_38 ) ;
V_35 = true ;
}
if ( V_35 )
return V_26 ;
}
}
#endif
F_18 ( & F_4 ( V_2 ) , L_3 ,
V_2 -> V_39 ) ;
return V_40 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_41 * V_42 = V_4 -> V_14 . V_15 ;
struct V_43 * V_44 = V_2 -> V_45 ;
int V_46 , V_12 = 0 ;
char * V_47 ;
if ( ! V_2 -> V_10 . V_11 ) {
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
struct V_21 * V_22 = & V_44 -> V_48 [ V_12 ] ;
unsigned int V_49 , V_50 = F_20 () ;
V_47 = * ( V_4 -> V_14 . V_51 + V_12 ) ;
snprintf ( V_47 , V_52 ,
L_4 , V_2 -> V_39 , V_12 ) ;
V_46 = F_21 ( V_42 [ V_12 ] . V_53 ,
F_7 , 0 , V_47 , V_22 ) ;
if ( V_46 ) {
F_3 ( & F_4 ( V_2 ) ,
L_5 ,
V_42 [ V_12 ] . V_53 , V_47 ) ;
return V_46 ;
}
V_49 = ( ( V_2 -> V_39 * V_7 -> V_13 ) +
V_12 ) % V_50 ;
F_22 ( V_42 [ V_12 ] . V_53 ,
F_23 ( V_49 ) ) ;
}
}
V_47 = * ( V_4 -> V_14 . V_51 + V_12 ) ;
snprintf ( V_47 , V_52 ,
L_6 , V_2 -> V_39 ) ;
V_46 = F_21 ( V_42 [ V_12 ] . V_53 , F_10 , 0 , V_47 , V_2 ) ;
if ( V_46 ) {
F_3 ( & F_4 ( V_2 ) ,
L_7 ,
V_42 [ V_12 ] . V_53 , V_47 ) ;
return V_46 ;
}
return V_46 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_41 * V_42 = V_4 -> V_14 . V_15 ;
struct V_43 * V_44 = V_2 -> V_45 ;
int V_12 = 0 ;
if ( V_4 -> V_14 . V_54 > 1 ) {
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
F_22 ( V_42 [ V_12 ] . V_53 , NULL ) ;
F_25 ( V_42 [ V_12 ] . V_53 , & V_44 -> V_48 [ V_12 ] ) ;
}
}
F_22 ( V_42 [ V_12 ] . V_53 , NULL ) ;
F_25 ( V_42 [ V_12 ] . V_53 , V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_12 ;
char * * V_51 ;
struct V_41 * V_15 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = 1 ;
if ( ! V_2 -> V_10 . V_11 )
V_9 += V_7 -> V_13 ;
V_15 = F_27 ( V_9 * sizeof( * V_15 ) ,
V_55 , F_28 ( & F_4 ( V_2 ) ) ) ;
if ( ! V_15 )
return - V_56 ;
V_51 = F_29 ( V_9 , sizeof( char * ) , V_55 ) ;
if ( ! V_51 ) {
F_30 ( V_15 ) ;
return - V_56 ;
}
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
* ( V_51 + V_12 ) = F_31 ( V_52 , V_55 ) ;
if ( ! ( * ( V_51 + V_12 ) ) )
goto V_57;
}
V_2 -> V_5 . V_14 . V_54 = V_9 ;
V_2 -> V_5 . V_14 . V_15 = V_15 ;
V_2 -> V_5 . V_14 . V_51 = V_51 ;
return 0 ;
V_57:
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ )
F_30 ( * ( V_51 + V_12 ) ) ;
F_30 ( V_15 ) ;
F_30 ( V_51 ) ;
return - V_56 ;
}
static void F_32 ( struct V_1 * V_2 )
{
char * * V_51 = V_2 -> V_5 . V_14 . V_51 ;
int V_12 ;
F_30 ( V_2 -> V_5 . V_14 . V_15 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 . V_14 . V_54 ; V_12 ++ )
F_30 ( * ( V_51 + V_12 ) ) ;
F_30 ( V_51 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_43 * V_58 = V_2 -> V_45 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ )
F_34 ( & V_58 -> V_48 [ V_12 ] . V_25 ,
V_59 ,
( unsigned long ) & V_58 -> V_48 [ V_12 ] ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_43 * V_58 = V_2 -> V_45 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
F_36 ( & V_58 -> V_48 [ V_12 ] . V_25 ) ;
F_37 ( & V_58 -> V_48 [ V_12 ] . V_25 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_35 ( V_2 ) ;
F_5 ( & V_2 -> V_5 ) ;
F_32 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_46 ;
V_46 = F_26 ( V_2 ) ;
if ( V_46 )
return V_46 ;
if ( F_1 ( V_2 ) )
goto V_60;
if ( F_33 ( V_2 ) )
goto V_60;
if ( F_19 ( V_2 ) )
goto V_60;
return 0 ;
V_60:
F_38 ( V_2 ) ;
return - V_18 ;
}
