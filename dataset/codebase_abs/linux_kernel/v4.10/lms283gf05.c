static void F_1 ( unsigned long V_1 , bool V_2 )
{
F_2 ( V_1 , ! V_2 ) ;
F_3 ( 100 ) ;
F_2 ( V_1 , V_2 ) ;
F_3 ( 20 ) ;
F_2 ( V_1 , ! V_2 ) ;
F_3 ( 20 ) ;
}
static void F_4 ( struct V_3 * V_4 ,
const struct V_5 * V_6 , int V_7 )
{
char V_8 [ 3 ] ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
V_8 [ 0 ] = 0x74 ;
V_8 [ 1 ] = 0x00 ;
V_8 [ 2 ] = V_6 [ V_9 ] . V_10 ;
F_5 ( V_4 , V_8 , 3 ) ;
V_8 [ 0 ] = 0x76 ;
V_8 [ 1 ] = V_6 [ V_9 ] . V_11 >> 8 ;
V_8 [ 2 ] = V_6 [ V_9 ] . V_11 & 0xff ;
F_5 ( V_4 , V_8 , 3 ) ;
F_3 ( V_6 [ V_9 ] . V_12 ) ;
}
}
static int F_6 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = F_7 ( V_14 ) ;
struct V_3 * V_4 = V_17 -> V_4 ;
struct V_18 * V_19 = F_8 ( & V_4 -> V_20 ) ;
if ( V_15 <= V_21 ) {
if ( V_19 )
F_1 ( V_19 -> V_22 ,
V_19 -> V_23 ) ;
F_4 ( V_4 , V_24 , F_9 ( V_24 ) ) ;
} else {
F_4 ( V_4 , V_25 , F_9 ( V_25 ) ) ;
if ( V_19 )
F_2 ( V_19 -> V_22 ,
V_19 -> V_23 ) ;
}
return 0 ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 = F_8 ( & V_4 -> V_20 ) ;
struct V_13 * V_14 ;
int V_26 = 0 ;
if ( V_19 != NULL ) {
V_26 = F_11 ( & V_4 -> V_20 , V_19 -> V_22 ,
V_27 | ( ! V_19 -> V_23 ?
V_28 : V_29 ) ,
L_1 ) ;
if ( V_26 )
return V_26 ;
}
V_17 = F_12 ( & V_4 -> V_20 , sizeof( struct V_16 ) ,
V_30 ) ;
if ( V_17 == NULL )
return - V_31 ;
V_14 = F_13 ( & V_4 -> V_20 , L_2 , & V_4 -> V_20 , V_17 ,
& V_32 ) ;
if ( F_14 ( V_14 ) )
return F_15 ( V_14 ) ;
V_17 -> V_4 = V_4 ;
V_17 -> V_14 = V_14 ;
F_16 ( V_4 , V_17 ) ;
if ( V_19 )
F_1 ( V_19 -> V_22 , V_19 -> V_23 ) ;
F_4 ( V_4 , V_24 , F_9 ( V_24 ) ) ;
return 0 ;
}
