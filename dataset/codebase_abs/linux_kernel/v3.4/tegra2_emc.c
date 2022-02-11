static inline void F_1 ( T_1 V_1 , unsigned long V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline T_1 F_3 ( unsigned long V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
long F_5 ( unsigned long V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
int V_8 = - 1 ;
unsigned long V_9 = V_10 ;
if ( ! V_11 )
return - V_12 ;
V_6 = V_11 -> V_13 . V_14 ;
F_6 ( L_1 , V_15 , V_4 ) ;
V_4 = V_4 / 2 / 1000 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_16 ; V_7 ++ ) {
if ( V_6 -> V_17 [ V_7 ] . V_4 >= V_4 &&
( V_6 -> V_17 [ V_7 ] . V_4 - V_4 ) < V_9 ) {
V_9 = V_6 -> V_17 [ V_7 ] . V_4 - V_4 ;
V_8 = V_7 ;
}
}
if ( V_8 < 0 )
return - V_12 ;
F_6 ( L_2 , V_15 , V_6 -> V_17 [ V_8 ] . V_4 ) ;
return V_6 -> V_17 [ V_8 ] . V_4 * 2 * 1000 ;
}
int F_7 ( unsigned long V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
int V_18 ;
if ( ! V_11 )
return - V_12 ;
V_6 = V_11 -> V_13 . V_14 ;
V_4 = V_4 / 2 / 1000 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_16 ; V_7 ++ )
if ( V_6 -> V_17 [ V_7 ] . V_4 == V_4 )
break;
if ( V_7 >= V_6 -> V_16 )
return - V_12 ;
F_6 ( L_3 , V_15 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_1 ( V_6 -> V_17 [ V_7 ] . V_20 [ V_18 ] , V_21 [ V_18 ] ) ;
F_3 ( V_6 -> V_17 [ V_7 ] . V_20 [ V_19 - 1 ] ) ;
return 0 ;
}
static struct V_22 * F_8 ( struct V_22 * V_23 )
{
struct V_22 * V_24 ;
T_1 V_25 ;
F_9 (np, iter) {
if ( F_10 ( V_23 , L_4 , & V_25 ) )
continue;
if ( V_25 == V_26 )
return F_11 ( V_24 ) ;
}
return NULL ;
}
static struct V_5 * F_12 (
struct V_27 * V_28 )
{
struct V_22 * V_23 = V_28 -> V_13 . V_29 ;
struct V_22 * V_30 , * V_24 ;
struct V_5 * V_6 ;
int V_31 , V_7 , V_16 ;
if ( ! V_23 )
return NULL ;
if ( F_13 ( V_23 , L_5 , NULL ) ) {
V_30 = F_8 ( V_23 ) ;
if ( ! V_30 )
F_14 ( & V_28 -> V_13 ,
L_6 ,
V_26 ) ;
} else
V_30 = F_11 ( V_23 ) ;
if ( ! V_30 )
return NULL ;
V_16 = 0 ;
F_9 (tnp, iter)
if ( F_15 ( V_24 , L_7 ) )
V_16 ++ ;
if ( ! V_16 ) {
V_6 = NULL ;
goto V_32;
}
V_6 = F_16 ( & V_28 -> V_13 , sizeof( * V_6 ) , V_33 ) ;
V_6 -> V_17 = F_16 ( & V_28 -> V_13 ,
sizeof( * V_6 -> V_17 ) * V_16 ,
V_33 ) ;
V_7 = 0 ;
F_9 (tnp, iter) {
T_1 V_34 ;
V_31 = F_10 ( V_24 , L_8 , & V_34 ) ;
if ( V_31 ) {
F_17 ( & V_28 -> V_13 , L_9 ,
V_24 -> V_35 ) ;
continue;
}
V_6 -> V_17 [ V_7 ] . V_4 = V_34 ;
V_31 = F_18 ( V_24 , L_10 ,
V_6 -> V_17 [ V_7 ] . V_20 ,
V_19 ) ;
if ( V_31 ) {
F_17 ( & V_28 -> V_13 ,
L_11 ,
V_24 -> V_35 ) ;
continue;
}
V_7 ++ ;
}
V_6 -> V_16 = V_7 ;
V_32:
F_19 ( V_30 ) ;
return V_6 ;
}
static struct V_5 * F_12 (
struct V_27 * V_28 )
{
return NULL ;
}
static struct V_5 T_2 * F_20 ( struct V_27 * V_28 )
{
struct V_36 * V_37 = F_21 ( NULL , L_12 ) ;
struct V_5 * V_6 ;
unsigned long V_38 ;
int V_7 ;
F_22 ( V_28 -> V_13 . V_14 ) ;
F_23 ( F_24 ( V_37 ) ) ;
V_6 = F_16 ( & V_28 -> V_13 , sizeof( * V_6 ) , V_33 ) ;
V_6 -> V_17 = F_16 ( & V_28 -> V_13 , sizeof( * V_6 -> V_17 ) ,
V_33 ) ;
V_6 -> V_17 [ 0 ] . V_4 = F_25 ( V_37 ) / 2 / 1000 ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ )
V_6 -> V_17 [ 0 ] . V_20 [ V_7 ] = F_3 ( V_21 [ V_7 ] ) ;
V_6 -> V_16 = 1 ;
V_38 = V_6 -> V_17 [ 0 ] . V_4 ;
F_26 ( & V_28 -> V_13 , L_13
L_14 , V_38 * 2 , V_38 ) ;
return V_6 ;
}
static int T_2 F_27 ( struct V_27 * V_28 )
{
struct V_5 * V_6 ;
struct V_39 * V_40 ;
if ( ! V_41 ) {
F_17 ( & V_28 -> V_13 , L_15 ) ;
return - V_42 ;
}
V_40 = F_28 ( V_28 , V_43 , 0 ) ;
if ( ! V_40 ) {
F_17 ( & V_28 -> V_13 , L_16 ) ;
return - V_44 ;
}
V_3 = F_29 ( & V_28 -> V_13 , V_40 ) ;
if ( ! V_3 ) {
F_17 ( & V_28 -> V_13 , L_17 ) ;
return - V_44 ;
}
V_6 = V_28 -> V_13 . V_14 ;
if ( ! V_6 )
V_6 = F_12 ( V_28 ) ;
if ( ! V_6 )
V_6 = F_20 ( V_28 ) ;
V_28 -> V_13 . V_14 = V_6 ;
V_11 = V_28 ;
return 0 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_45 ) ;
}
