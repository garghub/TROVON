static void F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 * V_4 ,
int V_5 )
{
#ifdef F_2
int V_6 ;
F_3 ( V_2 , L_1 , V_3 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_4 ( L_2 , V_4 [ V_6 ] ) ;
F_4 ( L_3 ) ;
#endif
}
static int F_5 ( struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
T_1 * V_4 , * V_17 ;
int V_18 ;
unsigned long V_19 ;
int V_20 ;
V_19 = V_21 + F_6 ( V_22 ) ;
do {
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_23 = 1 ;
V_14 . V_24 = V_4 = V_8 -> V_25 ;
V_14 . V_5 = V_26 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
V_18 = F_9 ( V_11 -> V_27 , & V_16 ) ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
return V_18 ;
}
for ( V_17 = V_4 + V_26 ; V_4 != V_17 ; V_4 ++ ) {
if ( * V_4 == V_28 ) {
F_3 ( V_8 -> V_2 , L_5 ,
V_4 - V_8 -> V_25 ) ;
break;
}
}
if ( F_11 ( V_21 , V_19 ) ) {
F_12 ( V_8 -> V_2 , L_6 ) ;
return - V_29 ;
}
} while ( V_4 == V_17 );
V_20 = V_17 - ++ V_4 ;
F_13 ( V_20 < 0 || V_20 > V_8 -> V_30 ) ;
V_20 = F_14 ( V_20 , V_9 ) ;
memmove ( V_8 -> V_25 , V_4 , V_20 ) ;
V_4 = V_8 -> V_25 + V_20 ;
F_3 ( V_8 -> V_2 , L_7 ,
V_9 , V_20 ) ;
V_9 -= V_20 ;
while ( V_9 > 0 ) {
V_20 = F_14 ( V_9 , 256 ) ;
F_3 ( V_8 -> V_2 , L_8 ,
V_20 , V_9 , V_4 - V_8 -> V_25 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_23 = 1 ;
V_14 . V_24 = V_4 ;
V_14 . V_5 = V_20 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
F_13 ( ( T_1 * ) V_14 . V_24 - V_8 -> V_25 + V_20 >
V_8 -> V_30 ) ;
V_18 = F_9 ( V_11 -> V_27 , & V_16 ) ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
return V_18 ;
}
F_1 ( V_8 -> V_2 , L_9 , V_4 , V_20 ) ;
V_4 += V_20 ;
V_9 -= V_20 ;
}
F_3 ( V_8 -> V_2 , L_10 , V_4 - V_8 -> V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_6 , V_5 ;
T_1 * V_4 ;
int V_33 ;
int V_18 = 0 , V_34 ;
struct V_35 V_36 ;
V_5 = F_16 ( V_8 , V_32 ) ;
F_3 ( V_8 -> V_2 , L_11 , V_5 ) ;
if ( V_11 -> V_37 ) {
struct V_35 V_36 ;
unsigned long V_38 ;
F_17 ( & V_36 ) ;
V_38 = F_18 ( & V_36 ) - V_11 -> V_37 ;
if ( V_38 < V_39 )
F_19 ( V_38 ) ;
}
F_1 ( V_8 -> V_2 , L_12 , V_8 -> V_40 , V_5 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_41 = V_8 -> V_40 ;
V_14 . V_5 = V_5 ;
V_14 . V_23 = 1 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
V_18 = F_9 ( V_11 -> V_27 , & V_16 ) ;
if ( ! V_18 ) {
V_18 = F_5 ( V_8 ,
V_32 -> V_42 + V_43 ) ;
} else {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
}
F_7 ( & V_16 ) ;
if ( V_11 -> V_44 ) {
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_45 = V_11 -> V_44 ;
F_8 ( & V_14 , & V_16 ) ;
}
V_34 = F_9 ( V_11 -> V_27 , & V_16 ) ;
F_17 ( & V_36 ) ;
V_11 -> V_37 = F_18 ( & V_36 ) ;
if ( ! V_18 )
V_18 = V_34 ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
return V_18 ;
}
V_4 = V_8 -> V_25 ;
if ( V_4 [ 0 ] ) {
F_12 ( V_8 -> V_2 , L_13 ,
V_32 -> V_46 , V_4 [ 0 ] ) ;
F_1 ( V_8 -> V_2 , L_14 , V_4 , V_5 ) ;
return - V_47 ;
}
V_5 = V_4 [ 1 ] ;
V_33 = V_4 [ 0 ] + V_4 [ 1 ] ;
if ( V_5 > V_32 -> V_42 ) {
F_10 ( V_8 -> V_2 , L_15 ,
V_5 , V_32 -> V_42 ) ;
return - V_48 ;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_33 += V_4 [ V_6 + 2 ] ;
if ( V_32 -> V_42 )
V_32 -> V_49 [ V_6 ] = V_4 [ V_6 + 2 ] ;
}
V_33 &= 0xff ;
F_1 ( V_8 -> V_2 , L_16 , V_4 , V_5 + 3 ) ;
if ( V_33 != V_4 [ V_5 + 2 ] ) {
F_10 ( V_8 -> V_2 ,
L_17 ,
V_33 , V_4 [ V_5 + 2 ] ) ;
return - V_50 ;
}
return 0 ;
}
static void F_20 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_51 * V_52 = V_2 -> V_53 ;
T_2 V_54 ;
int V_18 ;
V_18 = F_21 ( V_52 , L_18 , & V_54 ) ;
if ( ! V_18 )
V_11 -> V_44 = V_54 ;
}
static int F_22 ( struct V_55 * V_27 )
{
struct V_1 * V_2 = & V_27 -> V_2 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int V_56 ;
V_27 -> V_57 = 8 ;
V_27 -> V_58 = V_59 ;
V_56 = F_23 ( V_27 ) ;
if ( V_56 < 0 )
return V_56 ;
V_11 = F_24 ( V_2 , sizeof( * V_11 ) , V_60 ) ;
if ( V_11 == NULL )
return - V_61 ;
V_11 -> V_27 = V_27 ;
V_8 = F_24 ( V_2 , sizeof( * V_8 ) , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
F_20 ( V_11 , V_2 ) ;
F_25 ( V_27 , V_8 ) ;
V_8 -> V_3 = L_19 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_12 = V_11 ;
V_8 -> V_62 = V_27 -> V_62 ;
V_8 -> V_63 = F_15 ;
V_8 -> V_64 = V_11 -> V_27 -> V_65 ;
V_8 -> V_66 = F_26 ( & V_11 -> V_27 -> V_2 ) ;
V_8 -> V_67 = & V_11 -> V_27 -> V_2 ;
V_8 -> V_30 = V_68 + V_26 ;
V_8 -> V_69 = V_68 ;
V_56 = F_27 ( V_8 ) ;
if ( V_56 ) {
F_10 ( V_2 , L_20 ) ;
return V_56 ;
}
return 0 ;
}
static int F_28 ( struct V_55 * V_27 )
{
struct V_7 * V_8 ;
V_8 = F_29 ( V_27 ) ;
F_30 ( V_8 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_32 ( V_2 ) ;
return F_33 ( V_8 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_32 ( V_2 ) ;
return F_35 ( V_8 ) ;
}
