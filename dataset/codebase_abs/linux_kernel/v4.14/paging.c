void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 -> V_4 [ 0 ] . V_5 )
return;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_4 [ V_3 ] ;
if ( ! V_8 -> V_5 ) {
F_2 ( V_2 ,
L_1 ,
V_3 ) ;
continue;
}
F_3 ( V_2 -> V_9 -> V_10 , V_8 -> V_11 ,
V_8 -> V_12 , V_13 ) ;
F_4 ( V_8 -> V_5 ,
F_5 ( V_8 -> V_12 ) ) ;
V_8 -> V_5 = NULL ;
}
F_6 ( V_2 -> V_9 -> V_14 ) ;
V_2 -> V_9 -> V_14 = NULL ;
V_2 -> V_9 -> V_15 = NULL ;
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 ;
T_1 V_20 = 0 ;
int V_21 , V_22 , V_23 , V_24 , V_25 ;
if ( V_2 -> V_4 [ 0 ] . V_5 )
return 0 ;
V_25 = F_8 ( V_2 -> V_9 -> V_10 ) ;
F_9 ( F_10 ( V_26 ) != V_27 ) ;
V_23 = V_17 -> V_28 / V_29 ;
V_2 -> V_30 =
F_11 ( V_23 , V_31 ) ;
V_2 -> V_32 =
V_23 -
V_31 * ( V_2 -> V_30 - 1 ) ;
F_2 ( V_2 ,
L_2 ,
V_2 -> V_30 ,
V_2 -> V_32 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_30 + 1 ; V_21 ++ ) {
V_24 = V_21 ? V_27 : V_29 ;
V_22 = F_5 ( V_24 ) ;
V_19 = F_12 ( V_33 , V_22 ) ;
if ( ! V_19 ) {
F_1 ( V_2 ) ;
return - V_34 ;
}
V_2 -> V_4 [ V_21 ] . V_5 = V_19 ;
V_2 -> V_4 [ V_21 ] . V_12 = V_24 ;
if ( V_25 ) {
V_20 = F_13 ( V_2 -> V_9 -> V_10 , V_19 , 0 ,
V_35 << V_22 ,
V_13 ) ;
if ( F_14 ( V_2 -> V_9 -> V_10 , V_20 ) ) {
F_1 ( V_2 ) ;
return - V_34 ;
}
V_2 -> V_4 [ V_21 ] . V_11 = V_20 ;
} else {
V_2 -> V_4 [ V_21 ] . V_11 =
V_36 |
V_21 << V_26 ;
}
if ( ! V_21 )
F_2 ( V_2 ,
L_3 ,
V_22 ) ;
else
F_2 ( V_2 ,
L_4 ,
V_22 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
int V_37 , V_38 ;
T_2 V_39 = 0 ;
for ( V_37 = 0 ; V_37 < V_17 -> V_40 ; V_37 ++ ) {
if ( V_17 -> V_41 [ V_37 ] . V_39 == V_42 ) {
V_37 ++ ;
break;
}
}
if ( V_37 >= V_17 -> V_40 - 1 ) {
F_16 ( V_2 , L_5 ) ;
F_1 ( V_2 ) ;
return - V_43 ;
}
F_2 ( V_2 , L_6 ,
V_37 ) ;
memcpy ( F_17 ( V_2 -> V_4 [ 0 ] . V_5 ) ,
V_17 -> V_41 [ V_37 ] . V_44 ,
V_2 -> V_4 [ 0 ] . V_12 ) ;
F_18 ( V_2 -> V_9 -> V_10 ,
V_2 -> V_4 [ 0 ] . V_11 ,
V_2 -> V_4 [ 0 ] . V_12 ,
V_13 ) ;
F_2 ( V_2 ,
L_7 ,
V_2 -> V_4 [ 0 ] . V_12 ) ;
V_37 ++ ;
for ( V_38 = 1 ; V_38 < V_2 -> V_30 ; V_38 ++ ) {
struct V_7 * V_19 = & V_2 -> V_4 [ V_38 ] ;
memcpy ( F_17 ( V_19 -> V_5 ) ,
V_17 -> V_41 [ V_37 ] . V_44 + V_39 ,
V_19 -> V_12 ) ;
F_18 ( V_2 -> V_9 -> V_10 ,
V_19 -> V_11 ,
V_19 -> V_12 ,
V_13 ) ;
F_2 ( V_2 ,
L_8 ,
V_2 -> V_4 [ V_38 ] . V_12 ,
V_38 ) ;
V_39 += V_2 -> V_4 [ V_38 ] . V_12 ;
}
if ( V_2 -> V_32 > 0 ) {
struct V_7 * V_19 = & V_2 -> V_4 [ V_38 ] ;
memcpy ( F_17 ( V_19 -> V_5 ) ,
V_17 -> V_41 [ V_37 ] . V_44 + V_39 ,
V_29 * V_2 -> V_32 ) ;
F_18 ( V_2 -> V_9 -> V_10 ,
V_19 -> V_11 ,
V_19 -> V_12 ,
V_13 ) ;
F_2 ( V_2 ,
L_9 ,
V_2 -> V_32 , V_38 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_16 * V_45 )
{
int V_46 ;
V_46 = F_7 ( V_2 , V_45 ) ;
if ( V_46 )
return V_46 ;
return F_15 ( V_2 , V_45 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_16 * V_45 )
{
struct V_47 V_48 = {
. V_49 = F_21 ( V_50 |
V_51 |
( V_2 -> V_32 <<
V_52 ) ) ,
. V_53 = F_21 ( V_26 ) ,
. V_54 = F_21 ( V_2 -> V_30 ) ,
} ;
struct V_55 V_56 = {
. V_57 = F_22 ( V_58 , V_59 , 0 ) ,
. V_60 = { sizeof( V_48 ) , } ,
. V_44 = { & V_48 , } ,
} ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_30 + 1 ; V_21 ++ ) {
T_1 V_61 = V_2 -> V_4 [ V_21 ] . V_11 ;
T_3 V_62 ;
V_61 = V_61 >> V_63 ;
V_62 = F_21 ( V_61 ) ;
V_48 . V_64 [ V_21 ] = V_62 ;
}
return F_23 ( V_2 -> V_9 , & V_56 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_46 ;
struct V_65 V_66 = {
. V_67 = F_21 ( V_68 ) ,
} ;
struct V_69 * V_70 ;
struct V_55 V_71 = {
. V_57 = F_22 ( V_72 , V_59 , 0 ) ,
. V_49 = V_73 | V_74 ,
. V_44 = { & V_66 , } ,
. V_60 = { sizeof( V_66 ) , } ,
} ;
V_46 = F_23 ( V_2 -> V_9 , & V_71 ) ;
if ( V_46 ) {
F_16 ( V_2 ,
L_10 ,
V_46 ) ;
return V_46 ;
}
V_70 = ( void * ) ( (struct V_75 * ) V_71 . V_76 ) -> V_44 ;
if ( V_70 -> V_67 != F_21 ( V_68 ) ) {
F_16 ( V_2 ,
L_11 ,
F_25 ( V_70 -> V_67 ) ) ;
V_46 = - V_77 ;
goto exit;
}
V_2 -> V_9 -> V_14 = F_26 ( V_27 +
V_29 ,
V_33 ) ;
if ( ! V_2 -> V_9 -> V_14 ) {
V_46 = - V_34 ;
goto exit;
}
V_2 -> V_9 -> V_78 = F_25 ( V_70 -> V_79 ) ;
V_2 -> V_9 -> V_15 = V_2 -> V_4 ;
F_2 ( V_2 ,
L_12 ,
V_2 -> V_9 -> V_78 ) ;
exit:
F_27 ( & V_71 ) ;
return V_46 ;
}
int F_28 ( struct V_1 * V_2 , enum V_80 type )
{
const struct V_16 * V_45 = & V_2 -> V_45 -> V_81 [ type ] ;
int V_46 ;
if ( V_2 -> V_9 -> V_82 -> V_83 )
return 0 ;
if ( ! V_45 -> V_28 )
return 0 ;
if ( ! F_8 ( V_2 -> V_9 -> V_10 ) ) {
V_46 = F_24 ( V_2 ) ;
if ( V_46 ) {
F_16 ( V_2 , L_13 ) ;
return V_46 ;
}
}
V_46 = F_19 ( V_2 , V_45 ) ;
if ( V_46 ) {
F_16 ( V_2 , L_14 ) ;
return V_46 ;
}
V_46 = F_20 ( V_2 , V_45 ) ;
if ( V_46 ) {
F_16 ( V_2 , L_15 ) ;
F_1 ( V_2 ) ;
return V_46 ;
}
return 0 ;
}
