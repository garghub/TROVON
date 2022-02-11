static inline void
F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static inline void
F_4 ( struct V_1 * V_2 )
{
F_2 ( L_2 ) ;
F_3 ( V_6 , V_2 -> V_4 + V_5 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 )
{
F_2 ( L_3 ) ;
F_3 ( V_7 , V_2 -> V_4 + V_8 ) ;
F_3 ( V_9 , V_2 -> V_4 + V_5 ) ;
}
static inline void
F_6 ( struct V_1 * V_2 )
{
F_2 ( L_4 ) ;
F_3 ( V_7 , V_2 -> V_4 + V_5 ) ;
F_3 ( V_9 , V_2 -> V_4 + V_5 ) ;
}
static inline int
F_7 ( struct V_1 * V_2 )
{
int V_10 ;
F_2 ( L_5 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ ) {
if ( ( ( F_8 ( V_2 -> V_4 + V_12 ) &
( V_9 | V_13 | V_6 | V_14 |
V_3 ) ) == 0 ) &&
( ( F_8 ( V_2 -> V_4 + V_15 ) &
( V_16 ) ) == 0 ) )
return 0 ;
F_9 ( 1 ) ;
}
return - V_17 ;
}
static inline T_1
F_10 ( struct V_1 * V_2 , T_1 V_18 )
{
F_2 ( L_6 ) ;
F_3 ( V_18 , V_2 -> V_4 + V_19 ) ;
return F_8 ( V_2 -> V_4 + V_15 ) & V_20 ;
}
static inline T_1
F_11 ( struct V_1 * V_2 )
{
F_2 ( L_7 ) ;
F_3 ( V_13 , V_2 -> V_4 + V_5 ) ;
while ( F_8 ( V_2 -> V_4 + V_12 ) & V_13 )
;
F_3 ( V_21 , V_2 -> V_4 + V_22 ) ;
return F_8 ( V_2 -> V_4 + V_23 ) ;
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_24 , int V_25 )
{
F_2 ( L_8 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
V_24 <<= 1 ;
if ( V_25 )
V_24 |= 1 ;
if ( F_10 ( V_2 , V_24 ) )
return - V_26 ;
F_7 ( V_2 ) ;
if ( F_8 ( V_2 -> V_4 + V_15 ) & V_27 )
return - V_26 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , unsigned char * V_28 ,
unsigned int V_29 )
{
int V_10 ;
T_1 V_30 ;
F_2 ( L_9 ) ;
V_10 = 0 ;
while ( V_10 < V_29 ) {
V_30 = F_11 ( V_2 ) ;
V_28 [ V_10 ++ ] = V_30 ;
if ( V_10 < V_29 )
F_5 ( V_2 ) ;
else
F_6 ( V_2 ) ;
}
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned char * V_28 ,
unsigned int V_29 )
{
int V_10 ;
T_1 V_30 ;
F_2 ( L_10 ) ;
V_10 = 0 ;
while ( V_10 < V_29 ) {
V_30 = V_28 [ V_10 ] ;
if ( F_10 ( V_2 , V_30 ) )
return - V_26 ;
F_7 ( V_2 ) ;
if ( F_8 ( V_2 -> V_4 + V_15 ) &
V_27 )
return - V_26 ;
V_10 ++ ;
}
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_15 ( struct V_31 * V_32 , struct V_33 * V_34 , int V_35 )
{
struct V_1 * V_2 = V_32 -> V_36 ;
struct V_33 * V_37 ;
int V_10 , V_38 = 0 ;
F_2 ( L_11 ) ;
for ( V_10 = 0 ; V_10 < V_35 ; V_10 ++ ) {
#define F_16 80
int V_39 ;
static char V_28 [ F_16 ] ;
char * V_40 = V_28 ;
V_37 = & V_34 [ V_10 ] ;
V_40 += sprintf ( V_28 , L_12 , V_37 -> V_29 ) ;
if ( ( V_37 -> V_41 & V_42 ) == 0 ) {
for ( V_39 = 0 ; V_39 < V_37 -> V_29 ; V_39 ++ ) {
if ( V_40 < & V_28 [ F_16 - 4 ] ) {
V_40 += sprintf ( V_40 , L_13 , V_37 -> V_28 [ V_39 ] ) ;
} else {
strcat ( V_40 , L_14 ) ;
break;
}
}
}
F_2 ( L_15 , V_10 , V_37 -> V_24 ,
( V_37 -> V_41 & V_42 ) ? L_16 : L_17 , V_28 ) ;
}
for ( V_10 = 0 ; ! V_38 && V_10 < V_35 ; V_10 ++ ) {
V_37 = & V_34 [ V_10 ] ;
V_38 = F_12 ( V_2 , V_37 -> V_24 , V_37 -> V_41 & V_42 ) ;
if ( V_38 || ! V_37 -> V_29 )
continue;
if ( V_37 -> V_41 & V_42 )
V_38 = F_13 ( V_2 , V_37 -> V_28 , V_37 -> V_29 ) ;
else
V_38 = F_14 ( V_2 , V_37 -> V_28 , V_37 -> V_29 ) ;
}
if ( V_38 == 0 )
V_38 = V_35 ;
return V_38 ;
}
static T_1
F_17 ( struct V_31 * V_2 )
{
F_2 ( L_18 ) ;
return V_43 | V_44 ;
}
static void F_18 ( struct V_1 * V_45 )
{
F_2 ( L_19 ) ;
F_3 ( 500 , V_45 -> V_4 + V_46 ) ;
F_3 ( V_47 , V_45 -> V_4 + V_8 ) ;
F_3 ( V_47 , V_45 -> V_4 + V_5 ) ;
F_3 ( ( V_48 | V_20 ) ,
( V_45 -> V_4 + V_22 ) ) ;
}
static void F_19 ( struct V_1 * V_45 )
{
F_2 ( L_20 ) ;
}
static int F_20 ( struct V_49 * V_50 )
{
struct V_1 * V_45 ;
struct V_51 * V_52 ;
int V_53 ;
F_2 ( L_21 ) ;
V_52 = F_21 ( V_50 , V_54 , 0 ) ;
if ( ! V_52 )
return - V_55 ;
V_45 = F_22 ( & V_50 -> V_56 , sizeof( struct V_1 ) ,
V_57 ) ;
if ( ! V_45 )
return - V_58 ;
#if 0
priv->base = bus_request_region(r->start, resource_size(r),
pdev->name);
#else
V_45 -> V_4 = V_52 -> V_59 ;
#endif
if ( ! V_45 -> V_4 )
return - V_60 ;
V_45 -> V_61 = 200 ;
V_45 -> V_62 = 200 ;
V_45 -> V_11 = 200 ;
V_45 -> V_2 . V_63 = V_50 -> V_64 ;
V_45 -> V_2 . V_65 = & V_66 ;
V_45 -> V_2 . V_36 = V_45 ;
V_45 -> V_2 . V_56 . V_67 = & V_50 -> V_56 ;
F_23 ( V_45 -> V_2 . V_68 , L_22 , sizeof( V_45 -> V_2 . V_68 ) ) ;
F_18 ( V_45 ) ;
V_53 = F_24 ( & V_45 -> V_2 ) ;
if ( V_53 ) {
F_19 ( V_45 ) ;
return V_53 ;
}
F_25 ( V_50 , V_45 ) ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 )
{
struct V_1 * V_45 = F_27 ( V_50 ) ;
F_2 ( L_23 ) ;
F_25 ( V_50 , NULL ) ;
F_28 ( & V_45 -> V_2 ) ;
F_19 ( V_45 ) ;
return 0 ;
}
static int
F_29 ( struct V_49 * V_50 , T_2 V_69 )
{
struct V_1 * V_45 = F_27 ( V_50 ) ;
F_30 ( & V_50 -> V_56 , L_20 ) ;
F_19 ( V_45 ) ;
return 0 ;
}
static int
F_31 ( struct V_49 * V_50 )
{
struct V_1 * V_45 = F_27 ( V_50 ) ;
F_30 ( & V_50 -> V_56 , L_19 ) ;
F_18 ( V_45 ) ;
return 0 ;
}
static int T_3
F_32 ( void )
{
F_2 ( L_24 ) ;
return F_33 ( & V_70 ) ;
}
static void T_4
F_34 ( void )
{
F_2 ( L_25 ) ;
F_35 ( & V_70 ) ;
}
