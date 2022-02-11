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
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_28 * V_29 =
& F_12 ( V_2 ) [ V_7 -> V_30 ( V_7 ) ] ;
void T_3 * V_31 = V_29 -> V_32 ;
T_1 V_33 ;
V_33 = ( ( F_13 ( V_31 , V_34 ) &
0x0000FFFF ) << 16 ) |
( ( F_13 ( V_31 , V_35 ) &
0x01FFFE00 ) >> 9 ) ;
if ( V_33 ) {
struct V_36 * V_11 ;
bool V_37 = false ;
int V_12 ;
F_14 ( V_2 , V_33 ) ;
F_15 (i, (const unsigned long *)&vf_mask,
(sizeof(vf_mask) * BITS_PER_BYTE)) {
V_11 = V_2 -> V_10 . V_11 + V_12 ;
if ( ! F_16 ( & V_11 -> V_38 ) ) {
F_17 ( & F_4 ( V_2 ) ,
L_2 ,
V_11 -> V_39 + 1 ) ;
continue;
}
F_9 ( & V_11 -> V_40 ) ;
V_37 = true ;
}
if ( V_37 )
return V_26 ;
}
}
#endif
F_18 ( & F_4 ( V_2 ) , L_3 ,
V_2 -> V_41 ) ;
return V_42 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_43 * V_44 = V_4 -> V_14 . V_15 ;
struct V_45 * V_46 = V_2 -> V_47 ;
int V_48 , V_12 = 0 ;
char * V_49 ;
if ( ! V_2 -> V_10 . V_11 ) {
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
struct V_21 * V_22 = & V_46 -> V_50 [ V_12 ] ;
unsigned int V_51 , V_52 = F_20 () ;
V_49 = * ( V_4 -> V_14 . V_53 + V_12 ) ;
snprintf ( V_49 , V_54 ,
L_4 , V_2 -> V_41 , V_12 ) ;
V_48 = F_21 ( V_44 [ V_12 ] . V_55 ,
F_7 , 0 , V_49 , V_22 ) ;
if ( V_48 ) {
F_3 ( & F_4 ( V_2 ) ,
L_5 ,
V_44 [ V_12 ] . V_55 , V_49 ) ;
return V_48 ;
}
V_51 = ( ( V_2 -> V_41 * V_7 -> V_13 ) +
V_12 ) % V_52 ;
F_22 ( V_44 [ V_12 ] . V_55 ,
F_23 ( V_51 ) ) ;
}
}
V_49 = * ( V_4 -> V_14 . V_53 + V_12 ) ;
snprintf ( V_49 , V_54 ,
L_6 , V_2 -> V_41 ) ;
V_48 = F_21 ( V_44 [ V_12 ] . V_55 , F_10 , 0 , V_49 , V_2 ) ;
if ( V_48 ) {
F_3 ( & F_4 ( V_2 ) ,
L_7 ,
V_44 [ V_12 ] . V_55 , V_49 ) ;
return V_48 ;
}
return V_48 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_43 * V_44 = V_4 -> V_14 . V_15 ;
struct V_45 * V_46 = V_2 -> V_47 ;
int V_12 = 0 ;
if ( V_4 -> V_14 . V_56 > 1 ) {
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
F_22 ( V_44 [ V_12 ] . V_55 , NULL ) ;
F_25 ( V_44 [ V_12 ] . V_55 , & V_46 -> V_50 [ V_12 ] ) ;
}
}
F_22 ( V_44 [ V_12 ] . V_55 , NULL ) ;
F_25 ( V_44 [ V_12 ] . V_55 , V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_12 ;
char * * V_53 ;
struct V_43 * V_15 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = 1 ;
if ( ! V_2 -> V_10 . V_11 )
V_9 += V_7 -> V_13 ;
V_15 = F_27 ( V_9 * sizeof( * V_15 ) ,
V_57 , F_28 ( & F_4 ( V_2 ) ) ) ;
if ( ! V_15 )
return - V_58 ;
V_53 = F_29 ( V_9 , sizeof( char * ) , V_57 ) ;
if ( ! V_53 ) {
F_30 ( V_15 ) ;
return - V_58 ;
}
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
* ( V_53 + V_12 ) = F_31 ( V_54 , V_57 ) ;
if ( ! ( * ( V_53 + V_12 ) ) )
goto V_59;
}
V_2 -> V_5 . V_14 . V_56 = V_9 ;
V_2 -> V_5 . V_14 . V_15 = V_15 ;
V_2 -> V_5 . V_14 . V_53 = V_53 ;
return 0 ;
V_59:
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ )
F_30 ( * ( V_53 + V_12 ) ) ;
F_30 ( V_15 ) ;
F_30 ( V_53 ) ;
return - V_58 ;
}
static void F_32 ( struct V_1 * V_2 )
{
char * * V_53 = V_2 -> V_5 . V_14 . V_53 ;
int V_12 ;
F_30 ( V_2 -> V_5 . V_14 . V_15 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_5 . V_14 . V_56 ; V_12 ++ )
F_30 ( * ( V_53 + V_12 ) ) ;
F_30 ( V_53 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_45 * V_60 = V_2 -> V_47 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ )
F_34 ( & V_60 -> V_50 [ V_12 ] . V_25 ,
V_61 ,
( unsigned long ) & V_60 -> V_50 [ V_12 ] ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_45 * V_60 = V_2 -> V_47 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
F_36 ( & V_60 -> V_50 [ V_12 ] . V_25 ) ;
F_37 ( & V_60 -> V_50 [ V_12 ] . V_25 ) ;
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
int V_48 ;
V_48 = F_26 ( V_2 ) ;
if ( V_48 )
return V_48 ;
if ( F_1 ( V_2 ) )
goto V_62;
if ( F_33 ( V_2 ) )
goto V_62;
if ( F_19 ( V_2 ) )
goto V_62;
return 0 ;
V_62:
F_38 ( V_2 ) ;
return - V_18 ;
}
