static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_7 ? 0 : 1 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_8 ? 0 : 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_3 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_12 ? 0 : 1 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_6 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_13 ? 1 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( F_8 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_14 ? 1 : 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_10 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_15 * V_16 , int V_17 )
{
int V_18 , V_19 = 0 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_20 = V_4 -> V_21 . V_22 ;
F_13 ( 4 , L_1 , V_23 ) ;
F_14 ( V_4 , V_24 , 0x01 ) ;
if ( ( ( V_4 -> V_21 . V_25 == V_26 ) ||
( V_4 -> V_21 . V_25 == V_27 ) ) &&
( V_4 -> V_21 . V_28 == V_16 -> V_29 ) ) {
if ( V_16 -> V_30 == 64 )
V_20 = V_31 ;
else
V_20 = V_32 ;
}
F_14 ( V_4 , V_33 , V_20 ) ;
F_14 ( V_4 , V_34 , V_16 -> V_29 << 1 ) ;
F_13 ( 4 , L_2 , V_16 -> V_29 ) ;
if ( V_16 -> V_30 == 0 ) {
F_14 ( V_4 , V_35 ,
V_36 ) ;
if ( ! F_11 ( V_2 ) )
return - V_37 ;
if ( F_4 ( V_2 ) )
return - V_37 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_30 ; ) {
F_13 ( 4 , L_3 , V_16 -> V_38 [ V_18 ] ) ;
F_14 ( V_4 , V_39 , V_16 -> V_38 [ V_18 ] ) ;
V_19 ++ ;
V_18 ++ ;
if ( ( V_19 >= 4 ) || ( V_18 >= V_16 -> V_30 ) ) {
if ( V_18 < V_16 -> V_30 )
F_14 ( V_4 , V_35 ,
V_40 |
V_41 ) ;
else
F_14 ( V_4 , V_35 ,
V_40 ) ;
V_19 = 0 ;
if ( ! F_9 ( V_2 ) )
return - V_37 ;
}
}
if ( ! F_11 ( V_2 ) )
return - V_37 ;
F_13 ( 4 , L_4 ) ;
return V_16 -> V_30 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_15 * V_16 , int V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_20 = V_4 -> V_21 . V_22 ;
int V_18 ;
F_13 ( 4 , L_1 , V_23 ) ;
F_14 ( V_4 , V_24 , 0x01 ) ;
if ( ( ( V_4 -> V_21 . V_25 == V_26 ) ||
( V_4 -> V_21 . V_25 == V_27 ) ) &&
( V_4 -> V_21 . V_28 == V_16 -> V_29 ) )
V_20 = V_32 ;
F_14 ( V_4 , V_33 , V_20 ) ;
F_14 ( V_4 , V_34 , V_16 -> V_29 << 1 ) ;
F_13 ( 4 , L_5 ) ;
if ( V_16 -> V_30 == 0 ) {
F_14 ( V_4 , V_35 ,
V_36 ) ;
if ( F_4 ( V_2 ) )
return - V_37 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_30 ; ) {
V_18 ++ ;
if ( V_18 < V_16 -> V_30 )
F_14 ( V_4 , V_35 ,
V_36 |
V_41 ) ;
else
F_14 ( V_4 , V_35 ,
V_36 ) ;
if ( ! F_7 ( V_2 ) )
return - V_37 ;
V_16 -> V_38 [ V_18 - 1 ] = F_2 ( V_4 , V_43 ) &
0xff ;
F_13 ( 4 , L_3 , V_16 -> V_38 [ V_18 - 1 ] ) ;
}
if ( ! F_11 ( V_2 ) )
return - V_37 ;
F_13 ( 4 , L_4 ) ;
return V_16 -> V_30 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_15 * V_44 , int V_45 )
{
int V_18 , V_46 = 0 ;
F_13 ( 4 , L_6 , V_23 , V_45 ) ;
for ( V_18 = 0 ; V_18 < V_45 ; V_18 ++ ) {
F_13 ( 4 , L_7 ,
V_23 , V_45 , V_44 [ V_18 ] . V_29 , V_44 [ V_18 ] . V_30 ) ;
if ( V_44 [ V_18 ] . V_47 & V_48 ) {
V_46 = F_15 ( V_2 , & V_44 [ V_18 ] , 0 ) ;
} else if ( V_18 + 1 < V_45 && ( V_44 [ V_18 + 1 ] . V_47 & V_48 ) &&
V_44 [ V_18 ] . V_29 == V_44 [ V_18 + 1 ] . V_29 ) {
V_46 = F_12 ( V_2 , & V_44 [ V_18 ] ,
V_44 [ V_18 + 1 ] . V_30 ) ;
if ( V_46 < 0 )
goto V_49;
V_18 ++ ;
V_46 = F_15 ( V_2 , & V_44 [ V_18 ] , 1 ) ;
} else {
V_46 = F_12 ( V_2 , & V_44 [ V_18 ] , 0 ) ;
}
if ( V_46 < 0 )
goto V_49;
}
return V_45 ;
V_49:
return V_46 ;
}
static T_2 F_17 ( struct V_1 * V_50 )
{
return V_51 | V_52 ;
}
static void F_18 ( char * V_53 , struct V_54 * V_55 )
{
unsigned char V_38 ;
int V_18 , V_56 ;
for ( V_18 = 0 ; V_18 < 128 ; V_18 ++ ) {
V_55 -> V_29 = V_18 ;
V_56 = F_19 ( V_55 , & V_38 , 0 ) ;
if ( V_56 < 0 )
continue;
F_20 ( L_8 ,
V_53 , V_18 << 1 , V_57 [ V_18 ] ? V_57 [ V_18 ] : L_9 ) ;
}
}
int F_21 ( struct V_3 * V_4 )
{
F_13 ( 1 , L_1 , V_23 ) ;
V_4 -> V_2 = V_58 ;
V_4 -> V_59 = V_60 ;
V_4 -> V_54 = V_61 ;
V_4 -> V_2 . V_4 . V_62 = & V_4 -> V_63 -> V_4 ;
F_22 ( V_4 -> V_2 . V_53 , V_64 ,
sizeof( V_4 -> V_2 . V_53 ) ) ;
V_4 -> V_2 . V_65 = & V_4 -> V_59 ;
V_4 -> V_2 . V_5 = V_4 ;
#ifdef F_23
F_24 ( & V_4 -> V_2 , & V_4 -> V_66 ) ;
#else
F_24 ( & V_4 -> V_2 , V_4 ) ;
#endif
F_25 ( & V_4 -> V_2 ) ;
V_4 -> V_54 . V_67 = & V_4 -> V_2 ;
if ( 0 == V_4 -> V_68 ) {
F_20 ( L_10 ) ;
if ( V_69 )
F_18 ( V_64 , & V_4 -> V_54 ) ;
} else
F_20 ( L_11 ) ;
return V_4 -> V_68 ;
}
int F_26 ( struct V_3 * V_4 )
{
F_27 ( & V_4 -> V_2 ) ;
return 0 ;
}
