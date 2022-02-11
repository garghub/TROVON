static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
V_1 -> V_4 [ 0 ] = '\0' ;
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
V_10 , V_2 , V_1 -> V_4 , 1 ,
V_11 ) ;
if ( V_3 < 0 ) {
F_4 ( L_1 , V_12 , V_3 ) ;
return V_3 ;
}
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_13 | V_8 | V_9 ,
V_14 , 0 , V_1 -> V_4 , 1 ,
V_11 ) ;
if ( V_3 < 0 ) {
F_4 ( L_2 , V_12 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_3 ;
V_1 -> V_4 [ 0 ] = '\0' ;
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
V_15 , 0 , V_1 -> V_4 , 1 ,
V_11 ) ;
if ( V_3 < 0 ) {
F_4 ( L_1 , V_12 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_1 , T_2 * V_16 , int V_17 , int V_18 )
{
int V_3 ;
int V_19 ;
V_1 -> V_4 [ 0 ] = '\0' ;
if ( V_18 )
F_7 ( & V_1 -> V_20 ) ;
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
V_21 , V_17 , V_1 -> V_4 ,
1 , V_11 ) ;
if ( V_18 )
F_8 ( & V_1 -> V_20 ) ;
if ( V_3 < 0 ) {
F_4 ( L_1 , V_12 , V_3 ) ;
return V_3 ;
}
V_3 = F_9 ( V_1 -> V_5 ,
F_10 ( V_1 -> V_5 , 0x81 ) ,
V_16 , V_17 , & V_19 , V_22 ) ;
if ( V_3 < 0 || V_19 != V_17 ) {
F_4 ( L_3 , V_3 , V_19 , V_17 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_5 = F_12 ( V_25 , struct V_26 , V_24 ) ;
struct V_1 * V_1 = & V_5 -> V_1 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_3 ;
T_2 * V_16 ;
T_2 * V_32 ;
V_32 = F_13 ( V_33 , V_34 | V_35 ) ;
if ( ! V_32 ) {
F_4 ( L_4 ) ;
goto V_36;
}
V_31 = V_1 -> V_37 . V_38 [ V_1 -> V_39 ] . V_40
+ V_41 ;
while ( V_1 -> V_42 && V_1 -> V_43 ) {
#ifdef F_14
if ( V_1 -> V_44 )
break;
#endif
V_27 = V_31 ;
V_29 = 0 ;
while ( V_27 > 0 && V_1 -> V_42 ) {
V_28 = V_27 > V_33 ?
V_33 : V_27 ;
V_3 = F_6 ( V_1 , V_32 , V_28 , 1 ) ;
if ( V_3 < 0 )
goto V_36;
F_15 ( V_45 ,
L_5 ,
V_28 , V_27 ) ;
V_27 -= V_28 ;
V_16 = V_32 ;
if ( ! V_29 ) {
V_30 = V_46 ;
V_16 += V_41 ;
V_28 -= V_41 ;
V_29 = 1 ;
} else if ( V_27 == 0 ) {
V_30 = V_47 ;
} else {
V_30 = V_48 ;
}
F_16 ( V_1 , V_30 ,
V_16 , V_28 ) ;
if ( V_30 == V_46 &&
V_27 == 0 )
F_16 ( V_1 , V_47 ,
NULL , 0 ) ;
}
if ( V_1 -> V_42 ) {
F_7 ( & V_1 -> V_20 ) ;
V_3 = F_5 ( V_1 ) ;
F_8 ( & V_1 -> V_20 ) ;
if ( V_3 < 0 )
goto V_36;
}
}
V_36:
if ( V_1 -> V_42 ) {
F_7 ( & V_1 -> V_20 ) ;
F_1 ( V_1 , V_49 ) ;
F_8 ( & V_1 -> V_20 ) ;
}
F_17 ( V_32 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_50 * V_51 )
{
struct V_37 * V_37 = & V_1 -> V_37 ;
struct V_26 * V_5 = (struct V_26 * ) V_1 ;
V_37 -> V_52 = 1 ;
V_37 -> V_53 = 64 ;
F_19 ( & V_5 -> V_24 , F_11 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_26 * V_5 = (struct V_26 * ) V_1 ;
F_8 ( & V_1 -> V_20 ) ;
F_21 ( V_5 -> V_54 ) ;
V_5 -> V_54 = NULL ;
F_7 ( & V_1 -> V_20 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
T_3 V_55 ;
int V_3 ;
V_3 = F_1 ( V_1 , V_49 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_1 ( V_1 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_6 ( V_1 , V_1 -> V_4 , 4 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_55 = F_23 ( ( V_57 * ) V_1 -> V_4 ) ;
V_3 = F_1 ( V_1 , V_49 ) ;
if ( V_3 < 0 )
return V_3 ;
F_15 ( V_58 , L_6 , V_55 ) ;
V_1 -> V_37 . V_38 = V_59 ;
V_1 -> V_37 . V_60 = F_24 ( V_59 ) ;
if ( ! ( V_55 & V_61 ) )
V_1 -> V_37 . V_60 -- ;
if ( V_55 & V_62 )
V_1 -> V_37 . V_63 = V_64 ;
else
V_1 -> V_37 . V_63 = V_64 |
V_65 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_26 * V_5 = (struct V_26 * ) V_1 ;
int V_3 ;
switch ( V_1 -> V_39 ) {
default:
F_15 ( V_66 , L_7 ) ;
V_3 = F_1 ( & V_5 -> V_1 , V_67 ) ;
break;
case 1 :
F_15 ( V_66 , L_8 ) ;
V_3 = F_1 ( & V_5 -> V_1 , V_68 ) ;
break;
case 0 :
F_15 ( V_66 , L_9 ) ;
V_3 = F_1 ( & V_5 -> V_1 , V_69 ) ;
}
if ( V_3 < 0 ) {
F_15 ( V_70 , L_10 ) ;
return V_3 ;
}
V_5 -> V_54 = F_26 ( V_71 ) ;
F_27 ( V_5 -> V_54 , & V_5 -> V_24 ) ;
return 0 ;
}
static int F_28 ( struct V_72 * V_73 ,
const struct V_50 * V_51 )
{
return F_29 ( V_73 , V_51 ,
& V_74 ,
sizeof( struct V_26 ) ,
V_75 ) ;
}
