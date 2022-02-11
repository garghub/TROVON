int F_1 ( void )
{
long V_1 ;
V_2 = F_2 ( V_3 [ V_4 ] , 0 , 0 ) ;
if ( F_3 ( V_2 ) ) {
V_1 = F_4 ( V_2 ) ;
F_5 ( L_1 ,
V_3 [ V_4 ] , V_1 ) ;
return V_1 ;
}
return 0 ;
}
static struct V_5 * F_6 ( enum V_6 V_7 )
{
struct V_5 * V_8 = V_2 ;
int V_1 ;
if ( V_7 != V_4 && V_7 < V_9 ) {
V_8 = F_2 ( V_3 [ V_7 ] , 0 , 0 ) ;
if ( F_3 ( V_8 ) ) {
V_1 = F_4 ( V_8 ) ;
F_5 ( L_2 ,
V_3 [ V_7 ] , V_1 ) ;
}
}
return V_8 ;
}
static void F_7 ( struct V_5 * V_8 )
{
if ( V_8 != V_2 )
F_8 ( V_8 ) ;
}
static int F_9 ( struct V_10 * V_10 ,
struct V_11 * V_12 ,
struct V_5 * V_8 )
{
T_1 V_13 , V_14 = 0 ;
char * V_15 ;
int V_1 , V_16 = 0 ;
struct {
struct V_17 V_18 ;
char V_19 [ F_10 ( V_8 ) ] ;
} V_20 ;
V_20 . V_18 . V_8 = V_8 ;
V_20 . V_18 . V_21 = 0 ;
V_12 -> V_22 = F_11 ( V_8 ) ;
V_1 = F_12 ( & V_20 . V_18 ) ;
if ( V_1 != 0 )
return V_1 ;
V_15 = F_13 ( V_23 , V_24 ) ;
if ( ! V_15 ) {
V_1 = - V_25 ;
goto V_26;
}
if ( ! ( V_10 -> V_27 & V_28 ) ) {
V_10 -> V_27 |= V_28 ;
V_16 = 1 ;
}
V_13 = F_14 ( F_15 ( V_10 ) ) ;
while ( V_14 < V_13 ) {
int V_29 ;
V_29 = F_16 ( V_10 , V_14 , V_15 , V_23 ) ;
if ( V_29 < 0 ) {
V_1 = V_29 ;
break;
}
if ( V_29 == 0 )
break;
V_14 += V_29 ;
V_1 = F_17 ( & V_20 . V_18 , V_15 , V_29 ) ;
if ( V_1 )
break;
}
F_18 ( V_15 ) ;
if ( ! V_1 )
V_1 = F_19 ( & V_20 . V_18 , V_12 -> V_30 ) ;
if ( V_16 )
V_10 -> V_27 &= ~ V_28 ;
V_26:
return V_1 ;
}
int F_20 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
struct V_5 * V_8 ;
int V_1 ;
V_8 = F_6 ( V_12 -> V_7 ) ;
if ( F_3 ( V_8 ) )
return F_4 ( V_8 ) ;
V_1 = F_9 ( V_10 , V_12 , V_8 ) ;
F_7 ( V_8 ) ;
return V_1 ;
}
static int F_21 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
int V_35 ,
struct V_11 * V_12 ,
struct V_5 * V_8 )
{
struct {
struct V_17 V_18 ;
char V_19 [ F_10 ( V_8 ) ] ;
} V_20 ;
int V_1 , V_36 ;
V_20 . V_18 . V_8 = V_8 ;
V_20 . V_18 . V_21 = 0 ;
V_12 -> V_22 = F_11 ( V_8 ) ;
V_1 = F_12 ( & V_20 . V_18 ) ;
if ( V_1 != 0 )
return V_1 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
if ( strcmp ( V_34 -> V_37 , V_38 ) != 0 ) {
V_1 = F_17 ( & V_20 . V_18 ,
( const V_39 * ) & V_32 [ V_36 ] . V_40 ,
sizeof( V_32 [ V_36 ] . V_40 ) ) ;
if ( V_1 )
break;
}
V_1 = F_17 ( & V_20 . V_18 , V_32 [ V_36 ] . V_41 ,
V_32 [ V_36 ] . V_40 ) ;
if ( V_1 )
break;
}
if ( ! V_1 )
V_1 = F_19 ( & V_20 . V_18 , V_12 -> V_30 ) ;
return V_1 ;
}
int F_22 ( struct V_31 * V_32 ,
struct V_33 * V_20 , int V_35 ,
struct V_11 * V_12 )
{
struct V_5 * V_8 ;
int V_1 ;
V_8 = F_6 ( V_12 -> V_7 ) ;
if ( F_3 ( V_8 ) )
return F_4 ( V_8 ) ;
V_1 = F_21 ( V_32 , V_20 , V_35 ,
V_12 , V_8 ) ;
F_7 ( V_8 ) ;
return V_1 ;
}
static void T_2 F_23 ( int V_42 , V_39 * V_43 )
{
if ( ! V_44 )
return;
if ( F_24 ( V_45 , V_42 , V_43 ) != 0 )
F_5 ( L_3 ) ;
}
static int T_2 F_25 ( char * V_30 ,
struct V_5 * V_8 )
{
V_39 V_46 [ V_47 ] ;
int V_1 , V_36 ;
struct {
struct V_17 V_18 ;
char V_19 [ F_10 ( V_8 ) ] ;
} V_20 ;
V_20 . V_18 . V_8 = V_8 ;
V_20 . V_18 . V_21 = 0 ;
V_1 = F_12 ( & V_20 . V_18 ) ;
if ( V_1 != 0 )
return V_1 ;
for ( V_36 = V_48 ; V_36 < V_49 ; V_36 ++ ) {
F_23 ( V_36 , V_46 ) ;
V_1 = F_17 ( & V_20 . V_18 , V_46 , V_47 ) ;
}
if ( ! V_1 )
F_19 ( & V_20 . V_18 , V_30 ) ;
return V_1 ;
}
int T_2 F_26 ( struct V_11 * V_12 )
{
struct V_5 * V_8 ;
int V_1 ;
V_8 = F_6 ( V_12 -> V_7 ) ;
if ( F_3 ( V_8 ) )
return F_4 ( V_8 ) ;
V_12 -> V_22 = F_11 ( V_8 ) ;
V_1 = F_25 ( V_12 -> V_30 , V_8 ) ;
F_7 ( V_8 ) ;
return V_1 ;
}
