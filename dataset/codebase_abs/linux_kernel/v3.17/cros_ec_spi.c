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
while ( true ) {
unsigned long V_23 = V_21 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_24 = 1 ;
V_14 . V_25 = V_4 = V_8 -> V_26 ;
V_14 . V_5 = V_27 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
V_18 = F_9 ( V_11 -> V_28 , & V_16 ) ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
return V_18 ;
}
for ( V_17 = V_4 + V_27 ; V_4 != V_17 ; V_4 ++ ) {
if ( * V_4 == V_29 ) {
F_3 ( V_8 -> V_2 , L_5 ,
V_4 - V_8 -> V_26 ) ;
break;
}
}
if ( V_4 != V_17 )
break;
if ( F_11 ( V_23 , V_19 ) ) {
F_12 ( V_8 -> V_2 , L_6 ) ;
return - V_30 ;
}
}
V_20 = V_17 - ++ V_4 ;
F_13 ( V_20 < 0 || V_20 > V_8 -> V_31 ) ;
V_20 = F_14 ( V_20 , V_9 ) ;
memmove ( V_8 -> V_26 , V_4 , V_20 ) ;
V_4 = V_8 -> V_26 + V_20 ;
F_3 ( V_8 -> V_2 , L_7 ,
V_9 , V_20 ) ;
V_9 -= V_20 ;
while ( V_9 > 0 ) {
V_20 = F_14 ( V_9 , 256 ) ;
F_3 ( V_8 -> V_2 , L_8 ,
V_20 , V_9 , V_4 - V_8 -> V_26 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_24 = 1 ;
V_14 . V_25 = V_4 ;
V_14 . V_5 = V_20 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
F_13 ( ( T_1 * ) V_14 . V_25 - V_8 -> V_26 + V_20 >
V_8 -> V_31 ) ;
V_18 = F_9 ( V_11 -> V_28 , & V_16 ) ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
return V_18 ;
}
F_1 ( V_8 -> V_2 , L_9 , V_4 , V_20 ) ;
V_4 += V_20 ;
V_9 -= V_20 ;
}
F_3 ( V_8 -> V_2 , L_10 , V_4 - V_8 -> V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_6 , V_5 ;
T_1 * V_4 ;
int V_34 ;
int V_18 = 0 , V_35 ;
F_16 ( & V_11 -> V_36 ) ;
V_5 = F_17 ( V_8 , V_33 ) ;
F_3 ( V_8 -> V_2 , L_11 , V_5 ) ;
if ( V_11 -> V_37 ) {
unsigned long V_38 ;
V_38 = F_18 () - V_11 -> V_37 ;
if ( V_38 < V_39 )
F_19 ( V_39 - V_38 ) ;
}
F_1 ( V_8 -> V_2 , L_12 , V_8 -> V_40 , V_5 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_41 = V_8 -> V_40 ;
V_14 . V_5 = V_5 ;
V_14 . V_24 = 1 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
V_18 = F_9 ( V_11 -> V_28 , & V_16 ) ;
if ( ! V_18 ) {
V_18 = F_5 ( V_8 ,
V_33 -> V_42 + V_43 ) ;
} else {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
}
F_7 ( & V_16 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_44 = V_11 -> V_45 ;
F_8 ( & V_14 , & V_16 ) ;
V_35 = F_9 ( V_11 -> V_28 , & V_16 ) ;
V_11 -> V_37 = F_18 () ;
if ( ! V_18 )
V_18 = V_35 ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_4 , V_18 ) ;
goto exit;
}
V_4 = V_8 -> V_26 ;
V_33 -> V_46 = V_4 [ 0 ] ;
V_18 = F_20 ( V_8 , V_33 ) ;
if ( V_18 )
goto exit;
V_5 = V_4 [ 1 ] ;
V_34 = V_4 [ 0 ] + V_4 [ 1 ] ;
if ( V_5 > V_33 -> V_42 ) {
F_10 ( V_8 -> V_2 , L_13 ,
V_5 , V_33 -> V_42 ) ;
V_18 = - V_47 ;
goto exit;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_34 += V_4 [ V_6 + 2 ] ;
if ( V_33 -> V_42 )
V_33 -> V_48 [ V_6 ] = V_4 [ V_6 + 2 ] ;
}
V_34 &= 0xff ;
F_1 ( V_8 -> V_2 , L_14 , V_4 , V_5 + 3 ) ;
if ( V_34 != V_4 [ V_5 + 2 ] ) {
F_10 ( V_8 -> V_2 ,
L_15 ,
V_34 , V_4 [ V_5 + 2 ] ) ;
V_18 = - V_49 ;
goto exit;
}
V_18 = V_5 ;
exit:
F_21 ( & V_11 -> V_36 ) ;
return V_18 ;
}
static void F_22 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
T_2 V_53 ;
int V_18 ;
V_18 = F_23 ( V_51 , L_16 , & V_53 ) ;
if ( ! V_18 )
V_11 -> V_45 = V_53 ;
}
static int F_24 ( struct V_54 * V_28 )
{
struct V_1 * V_2 = & V_28 -> V_2 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int V_55 ;
V_28 -> V_56 = 8 ;
V_28 -> V_57 = V_58 ;
V_55 = F_25 ( V_28 ) ;
if ( V_55 < 0 )
return V_55 ;
V_11 = F_26 ( V_2 , sizeof( * V_11 ) , V_59 ) ;
if ( V_11 == NULL )
return - V_60 ;
V_11 -> V_28 = V_28 ;
F_27 ( & V_11 -> V_36 ) ;
V_8 = F_26 ( V_2 , sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
F_22 ( V_11 , V_2 ) ;
F_28 ( V_28 , V_8 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_12 = V_11 ;
V_8 -> V_61 = V_28 -> V_61 ;
V_8 -> V_62 = F_15 ;
V_8 -> V_63 = V_11 -> V_28 -> V_64 ;
V_8 -> V_65 = F_29 ( & V_11 -> V_28 -> V_2 ) ;
V_8 -> V_66 = & V_11 -> V_28 -> V_2 ;
V_8 -> V_31 = V_67 + V_27 ;
V_8 -> V_68 = V_67 ;
V_55 = F_30 ( V_8 ) ;
if ( V_55 ) {
F_10 ( V_2 , L_17 ) ;
return V_55 ;
}
F_31 ( & V_28 -> V_2 , true ) ;
return 0 ;
}
static int F_32 ( struct V_54 * V_28 )
{
struct V_7 * V_8 ;
V_8 = F_33 ( V_28 ) ;
F_34 ( V_8 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_36 ( V_2 ) ;
return F_37 ( V_8 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_36 ( V_2 ) ;
return F_39 ( V_8 ) ;
}
