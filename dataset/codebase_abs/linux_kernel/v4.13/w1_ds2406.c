static T_1 F_1 (
struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
T_4 V_10 [ 6 ] = { V_11 , 7 , 0 , 0 , 0 , 0 } ;
struct V_12 * V_13 = F_2 ( V_4 ) ;
T_5 V_14 = 0 ;
int V_15 ;
T_1 V_16 = 1 ;
if ( V_8 != 0 )
return 0 ;
if ( ! V_7 )
return - V_17 ;
F_3 ( & V_13 -> V_18 -> V_19 ) ;
if ( F_4 ( V_13 ) ) {
F_5 ( & V_13 -> V_18 -> V_19 ) ;
return - V_20 ;
}
F_6 ( V_13 -> V_18 , V_10 , 3 ) ;
F_7 ( V_13 -> V_18 , V_10 + 3 , 3 ) ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ )
V_14 = F_8 ( V_14 , V_10 [ V_15 ] ) ;
if ( V_14 == 0xb001 )
* V_7 = ( ( V_10 [ 3 ] >> 5 ) & 3 ) | 0x30 ;
else
V_16 = - V_20 ;
F_5 ( & V_13 -> V_18 -> V_19 ) ;
return V_16 ;
}
static T_1 F_9 (
struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_12 * V_13 = F_2 ( V_4 ) ;
T_4 V_10 [ 6 ] = { V_21 , 7 , 0 , 0 , 0 , 0 } ;
T_5 V_14 = 0 ;
int V_15 ;
T_1 V_16 = 1 ;
if ( V_9 != 1 || V_8 != 0 )
return - V_22 ;
F_3 ( & V_13 -> V_18 -> V_19 ) ;
if ( F_4 ( V_13 ) ) {
F_5 ( & V_13 -> V_18 -> V_19 ) ;
return - V_20 ;
}
V_10 [ 3 ] = ( ( ( * V_7 ) & 3 ) << 5 ) | 0x1F ;
F_6 ( V_13 -> V_18 , V_10 , 4 ) ;
F_7 ( V_13 -> V_18 , V_10 + 4 , 2 ) ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ )
V_14 = F_8 ( V_14 , V_10 [ V_15 ] ) ;
if ( V_14 == 0xb001 )
F_10 ( V_13 -> V_18 , 0xFF ) ;
else
V_16 = - V_20 ;
F_5 ( & V_13 -> V_18 -> V_19 ) ;
return V_16 ;
}
static int F_11 ( struct V_12 * V_13 )
{
int V_23 = 0 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_24 && ! V_23 ; ++ V_15 )
V_23 = F_12 (
& V_13 -> V_25 . V_4 ,
& ( V_26 [ V_15 ] ) ) ;
if ( V_23 )
while ( -- V_15 >= 0 )
F_13 ( & V_13 -> V_25 . V_4 ,
& ( V_26 [ V_15 ] ) ) ;
return V_23 ;
}
static void F_14 ( struct V_12 * V_13 )
{
int V_15 ;
for ( V_15 = V_24 - 1 ; V_15 >= 0 ; -- V_15 )
F_13 ( & V_13 -> V_25 . V_4 ,
& ( V_26 [ V_15 ] ) ) ;
}
