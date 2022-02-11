struct V_1 * F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_3 , V_5 ) ;
if ( ! V_8 )
return NULL ;
V_3 -> V_9 = V_8 ;
V_6 = F_3 ( V_3 , 1 ) ;
if ( ! V_6 )
V_6 = F_3 ( V_3 , 0 ) ;
if ( V_6 ) {
if ( V_6 -> V_10 > V_3 -> V_10 ) {
F_4 ( V_11 L_1 ,
( unsigned long ) V_6 -> V_10 >> 10 ,
( unsigned long ) V_3 -> V_10 >> 10 ) ;
V_6 -> V_10 = V_3 -> V_10 ;
}
return V_6 ;
}
F_4 ( V_11 L_2 ) ;
F_5 ( V_8 -> V_12 ) ;
F_5 ( V_8 ) ;
V_3 -> V_9 = NULL ;
return NULL ;
}
static struct V_7 * F_2 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_7 V_8 ;
struct V_7 * V_13 ;
unsigned long * V_14 ;
int V_15 , V_16 , V_17 ;
int V_18 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
if ( ! F_6 ( V_3 , V_5 , & V_8 ) ) {
F_7 ( L_3 ,
V_5 -> V_19 , V_3 -> V_19 ) ;
return NULL ;
}
#if 0
if (cfi.cfiq->NumEraseRegions == 0) {
printk(KERN_WARNING "Number of erase regions is zero\n");
kfree(cfi.cfiq);
return NULL;
}
#endif
V_8 . V_20 = V_8 . V_12 -> V_21 ;
if ( F_8 ( & V_8 ) ) {
;
} else if ( F_9 ( & V_8 ) ) {
V_8 . V_20 ++ ;
} else if ( F_10 ( ( & V_8 ) ) ) {
V_8 . V_20 += 2 ;
} else if ( F_11 ( & V_8 ) ) {
V_8 . V_20 += 3 ;
} else {
F_12 () ;
}
V_8 . V_22 = 1 ;
V_18 = V_3 -> V_10 >> V_8 . V_20 ;
if ( ! V_18 ) {
F_4 ( V_11 L_4 ) ;
V_18 = 1 ;
}
V_17 = sizeof( long ) * F_13 ( V_18 , V_23 ) ;
V_14 = F_14 ( V_17 , V_24 ) ;
if ( ! V_14 ) {
F_4 ( V_11 L_5 , V_3 -> V_19 ) ;
F_5 ( V_8 . V_12 ) ;
return NULL ;
}
F_15 ( 0 , V_14 ) ;
for ( V_15 = 1 ; V_15 < V_18 ; V_15 ++ ) {
V_5 -> V_25 ( V_3 , V_15 << V_8 . V_20 , V_14 , & V_8 ) ;
}
V_13 = F_16 ( sizeof( struct V_7 ) + V_8 . V_22 * sizeof( struct V_26 ) , V_24 ) ;
if ( ! V_13 ) {
F_4 ( V_11 L_6 , V_3 -> V_19 ) ;
F_5 ( V_8 . V_12 ) ;
F_5 ( V_14 ) ;
return NULL ;
}
memcpy ( V_13 , & V_8 , sizeof( V_8 ) ) ;
memset ( & V_13 -> V_27 [ 0 ] , 0 , sizeof( struct V_26 ) * V_8 . V_22 ) ;
for ( V_15 = 0 , V_16 = 0 ; ( V_16 < V_8 . V_22 ) && ( V_15 < V_18 ) ; V_15 ++ ) {
if( F_17 ( V_15 , V_14 ) ) {
struct V_26 * V_28 = & V_13 -> V_27 [ V_16 ++ ] ;
V_28 -> V_29 = ( V_15 << V_8 . V_20 ) ;
V_28 -> V_30 = V_31 ;
F_18 ( & V_28 -> V_32 ) ;
F_19 ( & V_28 -> V_33 ) ;
}
}
F_5 ( V_14 ) ;
return V_13 ;
}
static int F_6 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_7 * V_8 )
{
int V_34 = ( F_20 ( V_3 ) / 4 ? : 1 ) ;
int V_18 = F_20 ( V_3 ) ;
int V_35 , type ;
for ( V_35 = V_18 ; V_35 >= V_34 ; V_35 >>= 1 ) {
if ( ! F_21 ( V_35 ) )
continue;
V_8 -> V_36 = V_35 ;
type = F_20 ( V_3 ) / V_35 ;
for (; type <= V_37 ; type <<= 1 ) {
V_8 -> V_38 = type ;
if ( V_5 -> V_25 ( V_3 , 0 , NULL , V_8 ) )
return 1 ;
}
}
return 0 ;
}
static inline struct V_1 * F_22 ( struct V_2 * V_3 ,
int V_39 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
T_1 type = V_39 ? V_8 -> V_12 -> V_40 : V_8 -> V_12 -> V_41 ;
#ifdef F_23
char V_42 [ 16 + sizeof( V_43 ) ] ;
T_2 * V_44 ;
sprintf ( V_42 , V_43 L_7 , type ) ;
V_44 = F_24 ( V_42 ) ;
if ( ! V_44 ) {
F_25 ( V_42 + sizeof( V_43 ) - 1 ) ;
V_44 = F_24 ( V_42 ) ;
}
if ( V_44 ) {
struct V_1 * V_6 ;
V_6 = (* V_44)( V_3 , V_39 ) ;
F_26 ( V_44 ) ;
return V_6 ;
}
#endif
F_4 ( V_45 L_8 , type ) ;
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 , int V_39 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
T_1 type = V_39 ? V_8 -> V_12 -> V_40 : V_8 -> V_12 -> V_41 ;
if ( type == V_46 || type == V_47 )
return NULL ;
switch( type ) {
#ifdef F_27
case V_48 :
case V_49 :
case V_50 :
return F_28 ( V_3 , V_39 ) ;
#endif
#ifdef F_29
case V_51 :
case V_52 :
case V_53 :
return F_30 ( V_3 , V_39 ) ;
#endif
#ifdef F_31
case V_54 :
return F_32 ( V_3 , V_39 ) ;
#endif
default:
return F_22 ( V_3 , V_39 ) ;
}
}
