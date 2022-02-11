static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = 1000 ;
unsigned int V_6 , V_7 ;
unsigned char V_8 ;
do {
V_7 = F_2 ( V_4 -> V_9 ) ;
if ( ! ( V_7 & V_10 ) )
return;
V_8 = F_2 ( V_4 -> V_11 ) & 0xff ;
V_6 = 0 ;
V_2 -> V_12 ++ ;
if ( V_7 & V_13 ) {
V_2 -> V_14 ++ ;
V_6 |= V_15 ;
} else if ( V_7 & V_16 ) {
V_2 -> V_17 ++ ;
V_6 |= V_18 ;
}
F_3 ( V_4 -> V_19 , V_8 , V_6 ) ;
} while ( -- V_5 );
F_4 ( & V_4 -> V_19 -> V_20 , L_1 ) ;
}
static T_1 F_5 ( int V_21 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ )
F_1 ( V_2 , & V_2 -> V_4 [ V_22 ] ) ;
return V_24 ;
}
static int F_6 ( struct V_25 * V_19 , unsigned char V_26 )
{
unsigned V_7 ;
struct V_3 * V_4 = V_19 -> V_27 ;
int V_5 = V_28 ;
do {
V_7 = F_2 ( V_4 -> V_9 ) ;
F_7 () ;
if ( V_7 & V_29 ) {
F_8 ( V_26 & 0xff , V_4 -> V_11 ) ;
return 0 ;
}
} while ( -- V_5 );
F_4 ( & V_19 -> V_20 , L_2 ) ;
return - V_30 ;
}
static int F_9 ( struct V_25 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_27 ;
F_8 ( V_31 , V_4 -> V_9 ) ;
return 0 ;
}
static void F_10 ( struct V_25 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_27 ;
F_8 ( F_2 ( V_4 -> V_9 ) & ~ V_31 ,
V_4 -> V_9 ) ;
}
static void T_2 * F_11 ( struct V_1 * V_2 ,
int V_32 , bool V_7 )
{
void T_2 * V_33 ;
V_33 = V_2 -> V_33 + 4 + 4 * V_32 ;
if ( V_7 )
V_33 += V_23 * 4 ;
return V_33 ;
}
static void F_12 ( struct V_1 * V_2 )
{
void T_2 * V_33 ;
T_3 V_26 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_33 = F_11 ( V_2 , V_22 , true ) ;
V_26 = F_2 ( V_33 ) ;
V_26 &= ~ ( V_31 | V_34 ) ;
F_8 ( V_26 , V_33 ) ;
}
}
static int F_13 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
int V_32 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_32 ] ;
struct V_25 * V_19 ;
V_19 = F_14 ( sizeof( struct V_25 ) , V_37 ) ;
if ( ! V_19 )
return - V_38 ;
V_19 -> V_39 . type = V_40 ;
V_19 -> V_41 = F_6 ;
V_19 -> V_42 = F_9 ;
V_19 -> V_43 = F_10 ;
snprintf ( V_19 -> V_44 , sizeof( V_19 -> V_44 ) , L_3 , V_32 ) ;
snprintf ( V_19 -> V_45 , sizeof( V_19 -> V_45 ) , L_4 , V_32 ) ;
V_19 -> V_27 = V_4 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_11 = F_11 ( V_2 , V_32 , false ) ;
V_4 -> V_9 = F_11 ( V_2 , V_32 , true ) ;
F_15 ( & V_36 -> V_20 , L_5 ,
V_32 , V_4 -> V_11 , V_4 -> V_9 ) ;
F_16 ( V_4 -> V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
int V_21 ;
int error , V_39 , V_22 ;
V_21 = F_18 ( V_36 , L_6 ) ;
if ( V_21 < 0 ) {
F_4 ( & V_36 -> V_20 , L_7 ) ;
return - V_48 ;
}
V_2 = F_19 ( & V_36 -> V_20 , sizeof( struct V_1 ) ,
V_37 ) ;
if ( ! V_2 ) {
F_4 ( & V_36 -> V_20 , L_8 ) ;
return - V_38 ;
}
V_47 = F_20 ( V_36 , V_49 , 0 ) ;
V_2 -> V_33 = F_21 ( & V_36 -> V_20 , V_47 ) ;
if ( F_22 ( V_2 -> V_33 ) )
return F_23 ( V_2 -> V_33 ) ;
F_24 ( & V_36 -> V_20 , L_9 ,
V_21 , V_2 -> V_33 , V_23 ) ;
V_39 = F_2 ( V_2 -> V_33 ) ;
if ( V_39 != V_50 ) {
F_4 ( & V_36 -> V_20 , L_10 ) ;
return - V_51 ;
}
F_12 ( V_2 ) ;
error = F_25 ( & V_36 -> V_20 , V_21 , F_5 ,
0 , L_11 , V_2 ) ;
if ( error ) {
F_4 ( & V_36 -> V_20 , L_12 ) ;
return error ;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
error = F_13 ( V_36 , V_2 , V_22 ) ;
if ( error ) {
while ( -- V_22 >= 0 )
F_26 ( V_2 -> V_4 [ V_22 ] . V_19 ) ;
return error ;
}
}
F_27 ( V_36 , V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_29 ( V_36 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ )
F_26 ( V_2 -> V_4 [ V_22 ] . V_19 ) ;
F_15 ( & V_36 -> V_20 , L_13 , V_2 -> V_12 ) ;
F_15 ( & V_36 -> V_20 , L_14 , V_2 -> V_14 ) ;
F_15 ( & V_36 -> V_20 , L_15 ,
V_2 -> V_17 ) ;
return 0 ;
}
