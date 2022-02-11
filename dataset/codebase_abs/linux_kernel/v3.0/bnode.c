void F_1 ( struct V_1 * V_2 , void * V_3 ,
int V_4 , int V_5 )
{
struct V_6 * V_6 ;
V_4 += V_2 -> V_7 ;
V_6 = V_2 -> V_6 [ 0 ] ;
memcpy ( V_3 , F_2 ( V_6 ) + V_4 , V_5 ) ;
F_3 ( V_6 ) ;
}
T_1 F_4 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_8 ;
F_1 ( V_2 , & V_8 , V_4 , 2 ) ;
return F_5 ( V_8 ) ;
}
T_3 F_6 ( struct V_1 * V_2 , int V_4 )
{
T_3 V_8 ;
F_1 ( V_2 , & V_8 , V_4 , 1 ) ;
return V_8 ;
}
void F_7 ( struct V_1 * V_2 , void * V_9 , int V_4 )
{
struct V_10 * V_11 ;
int V_12 ;
V_11 = V_2 -> V_11 ;
if ( V_2 -> type == V_13 ||
V_11 -> V_14 & V_15 )
V_12 = F_6 ( V_2 , V_4 ) + 1 ;
else
V_12 = V_11 -> V_16 + 1 ;
F_1 ( V_2 , V_9 , V_4 , V_12 ) ;
}
void F_8 ( struct V_1 * V_2 , void * V_3 , int V_4 , int V_5 )
{
struct V_6 * V_6 ;
V_4 += V_2 -> V_7 ;
V_6 = V_2 -> V_6 [ 0 ] ;
memcpy ( F_2 ( V_6 ) + V_4 , V_3 , V_5 ) ;
F_3 ( V_6 ) ;
F_9 ( V_6 ) ;
}
void F_10 ( struct V_1 * V_2 , int V_4 , T_1 V_8 )
{
T_2 V_17 = F_11 ( V_8 ) ;
F_8 ( V_2 , & V_17 , V_4 , 2 ) ;
}
void F_12 ( struct V_1 * V_2 , int V_4 , T_3 V_8 )
{
F_8 ( V_2 , & V_8 , V_4 , 1 ) ;
}
void F_13 ( struct V_1 * V_2 , int V_4 , int V_5 )
{
struct V_6 * V_6 ;
V_4 += V_2 -> V_7 ;
V_6 = V_2 -> V_6 [ 0 ] ;
memset ( F_2 ( V_6 ) + V_4 , 0 , V_5 ) ;
F_3 ( V_6 ) ;
F_9 ( V_6 ) ;
}
void F_14 ( struct V_1 * V_18 , int V_19 ,
struct V_1 * V_20 , int V_21 , int V_5 )
{
struct V_10 * V_11 ;
struct V_6 * V_22 , * V_23 ;
F_15 ( V_24 , L_1 , V_19 , V_21 , V_5 ) ;
if ( ! V_5 )
return;
V_11 = V_20 -> V_11 ;
V_21 += V_20 -> V_7 ;
V_19 += V_18 -> V_7 ;
V_22 = V_20 -> V_6 [ 0 ] ;
V_23 = V_18 -> V_6 [ 0 ] ;
memcpy ( F_2 ( V_23 ) + V_19 , F_2 ( V_22 ) + V_21 , V_5 ) ;
F_3 ( V_22 ) ;
F_3 ( V_23 ) ;
F_9 ( V_23 ) ;
}
void F_16 ( struct V_1 * V_2 , int V_19 , int V_21 , int V_5 )
{
struct V_6 * V_6 ;
void * V_25 ;
F_15 ( V_24 , L_2 , V_19 , V_21 , V_5 ) ;
if ( ! V_5 )
return;
V_21 += V_2 -> V_7 ;
V_19 += V_2 -> V_7 ;
V_6 = V_2 -> V_6 [ 0 ] ;
V_25 = F_2 ( V_6 ) ;
memmove ( V_25 + V_19 , V_25 + V_21 , V_5 ) ;
F_3 ( V_6 ) ;
F_9 ( V_6 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_26 V_27 ;
T_4 V_28 ;
int V_29 , V_4 , V_30 ;
F_15 ( V_24 , L_3 , V_2 -> V_31 ) ;
F_1 ( V_2 , & V_27 , 0 , sizeof( V_27 ) ) ;
F_15 ( V_24 , L_4 ,
F_18 ( V_27 . V_32 ) , F_18 ( V_27 . V_33 ) ,
V_27 . type , V_27 . V_34 , F_5 ( V_27 . V_35 ) ) ;
V_4 = V_2 -> V_11 -> V_36 - 2 ;
for ( V_29 = F_5 ( V_27 . V_35 ) ; V_29 >= 0 ; V_4 -= 2 , V_29 -- ) {
V_30 = F_4 ( V_2 , V_4 ) ;
F_15 ( V_24 , L_5 , V_30 ) ;
if ( V_29 && V_2 -> type == V_37 ) {
int V_38 ;
if ( V_2 -> V_11 -> V_14 & V_15 )
V_38 = ( F_6 ( V_2 , V_30 ) | 1 ) + 1 ;
else
V_38 = V_2 -> V_11 -> V_16 + 1 ;
F_15 ( V_24 , L_6 , V_38 , F_6 ( V_2 , V_30 ) ) ;
F_1 ( V_2 , & V_28 , V_30 + V_38 , 4 ) ;
F_15 ( V_24 , L_7 , F_18 ( V_28 ) ) ;
} else if ( V_29 && V_2 -> type == V_13 ) {
int V_38 ;
V_38 = F_6 ( V_2 , V_30 ) ;
F_15 ( V_24 , L_8 , V_38 ) ;
}
}
F_15 ( V_24 , L_9 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_1 * V_38 ;
T_4 V_28 ;
V_11 = V_2 -> V_11 ;
if ( V_2 -> V_33 ) {
V_38 = F_20 ( V_11 , V_2 -> V_33 ) ;
if ( F_21 ( V_38 ) )
return;
V_38 -> V_32 = V_2 -> V_32 ;
V_28 = F_22 ( V_38 -> V_32 ) ;
F_8 ( V_38 , & V_28 , F_23 ( struct V_26 , V_32 ) , 4 ) ;
F_24 ( V_38 ) ;
} else if ( V_2 -> type == V_13 )
V_11 -> V_39 = V_2 -> V_32 ;
if ( V_2 -> V_32 ) {
V_38 = F_20 ( V_11 , V_2 -> V_32 ) ;
if ( F_21 ( V_38 ) )
return;
V_38 -> V_33 = V_2 -> V_33 ;
V_28 = F_22 ( V_38 -> V_33 ) ;
F_8 ( V_38 , & V_28 , F_23 ( struct V_26 , V_33 ) , 4 ) ;
F_24 ( V_38 ) ;
} else if ( V_2 -> type == V_13 )
V_11 -> V_40 = V_2 -> V_33 ;
if ( ! V_2 -> V_33 && ! V_2 -> V_32 ) {
F_25 ( V_41 L_10 ) ;
}
if ( ! V_2 -> V_42 ) {
V_11 -> V_43 = 0 ;
V_11 -> V_44 = 0 ;
}
F_26 ( V_45 , & V_2 -> V_46 ) ;
}
static inline int F_27 ( T_5 V_47 )
{
V_47 = ( V_47 >> 16 ) + V_47 ;
V_47 += V_47 >> 8 ;
return V_47 & ( V_48 - 1 ) ;
}
struct V_1 * F_28 ( struct V_10 * V_11 , T_5 V_28 )
{
struct V_1 * V_2 ;
if ( V_28 >= V_11 -> V_49 ) {
F_25 ( V_50 L_11 , V_28 ) ;
return NULL ;
}
for ( V_2 = V_11 -> V_51 [ F_27 ( V_28 ) ] ;
V_2 ; V_2 = V_2 -> V_52 ) {
if ( V_2 -> V_31 == V_28 ) {
return V_2 ;
}
}
return NULL ;
}
static struct V_1 * F_29 ( struct V_10 * V_11 , T_5 V_28 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 , * V_55 ;
struct V_56 * V_57 ;
struct V_6 * V_6 ;
int V_58 , V_59 , V_29 , V_60 ;
T_6 V_4 ;
if ( V_28 >= V_11 -> V_49 ) {
F_25 ( V_50 L_11 , V_28 ) ;
return NULL ;
}
V_54 = V_11 -> V_61 -> V_62 ;
V_58 = sizeof( struct V_1 ) + V_11 -> V_63 *
sizeof( struct V_6 * ) ;
V_2 = F_30 ( V_58 , V_64 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_31 = V_28 ;
F_26 ( V_65 , & V_2 -> V_46 ) ;
F_31 ( & V_2 -> V_66 , 1 ) ;
F_15 ( V_67 , L_12 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 ) ;
F_32 ( & V_2 -> V_68 ) ;
F_33 ( & V_11 -> V_69 ) ;
V_55 = F_28 ( V_11 , V_28 ) ;
if ( ! V_55 ) {
V_60 = F_27 ( V_28 ) ;
V_2 -> V_52 = V_11 -> V_51 [ V_60 ] ;
V_11 -> V_51 [ V_60 ] = V_2 ;
V_11 -> V_70 ++ ;
} else {
F_34 ( & V_11 -> V_69 ) ;
F_35 ( V_2 ) ;
F_36 ( V_55 -> V_68 , ! F_37 ( V_65 , & V_55 -> V_46 ) ) ;
return V_55 ;
}
F_34 ( & V_11 -> V_69 ) ;
V_57 = V_11 -> V_61 -> V_71 ;
V_4 = ( T_6 ) V_28 * V_11 -> V_36 ;
V_59 = V_4 >> V_72 ;
V_2 -> V_7 = V_4 & ~ V_73 ;
for ( V_29 = 0 ; V_29 < V_11 -> V_63 ; V_29 ++ ) {
V_6 = F_38 ( V_57 , V_59 ++ , NULL ) ;
if ( F_21 ( V_6 ) )
goto V_74;
if ( F_39 ( V_6 ) ) {
F_40 ( V_6 ) ;
goto V_74;
}
F_40 ( V_6 ) ;
V_2 -> V_6 [ V_29 ] = V_6 ;
}
return V_2 ;
V_74:
F_26 ( V_75 , & V_2 -> V_46 ) ;
return V_2 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_1 * * V_76 ;
F_15 ( V_67 , L_13 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 , F_42 ( & V_2 -> V_66 ) ) ;
for ( V_76 = & V_2 -> V_11 -> V_51 [ F_27 ( V_2 -> V_31 ) ] ;
* V_76 && * V_76 != V_2 ; V_76 = & ( * V_76 ) -> V_52 )
;
F_43 ( ! * V_76 ) ;
* V_76 = V_2 -> V_52 ;
V_2 -> V_11 -> V_70 -- ;
}
struct V_1 * F_20 ( struct V_10 * V_11 , T_5 V_47 )
{
struct V_1 * V_2 ;
struct V_26 * V_27 ;
int V_29 , V_77 , V_4 , V_78 ;
int V_79 , V_80 ;
F_33 ( & V_11 -> V_69 ) ;
V_2 = F_28 ( V_11 , V_47 ) ;
if ( V_2 ) {
F_44 ( V_2 ) ;
F_34 ( & V_11 -> V_69 ) ;
F_36 ( V_2 -> V_68 , ! F_37 ( V_65 , & V_2 -> V_46 ) ) ;
if ( F_37 ( V_75 , & V_2 -> V_46 ) )
goto V_81;
return V_2 ;
}
F_34 ( & V_11 -> V_69 ) ;
V_2 = F_29 ( V_11 , V_47 ) ;
if ( ! V_2 )
return F_45 ( - V_82 ) ;
if ( F_37 ( V_75 , & V_2 -> V_46 ) )
goto V_81;
if ( ! F_37 ( V_65 , & V_2 -> V_46 ) )
return V_2 ;
V_27 = (struct V_26 * ) ( F_2 ( V_2 -> V_6 [ 0 ] ) + V_2 -> V_7 ) ;
V_2 -> V_33 = F_18 ( V_27 -> V_33 ) ;
V_2 -> V_32 = F_18 ( V_27 -> V_32 ) ;
V_2 -> V_35 = F_5 ( V_27 -> V_35 ) ;
V_2 -> type = V_27 -> type ;
V_2 -> V_34 = V_27 -> V_34 ;
F_3 ( V_2 -> V_6 [ 0 ] ) ;
switch ( V_2 -> type ) {
case V_83 :
case V_84 :
if ( V_2 -> V_34 != 0 )
goto V_81;
break;
case V_13 :
if ( V_2 -> V_34 != 1 )
goto V_81;
break;
case V_37 :
if ( V_2 -> V_34 <= 1 || V_2 -> V_34 > V_11 -> V_44 )
goto V_81;
break;
default:
goto V_81;
}
V_77 = V_11 -> V_36 - 2 ;
V_4 = F_4 ( V_2 , V_77 ) ;
if ( V_4 != sizeof( struct V_26 ) )
goto V_81;
for ( V_29 = 1 ; V_29 <= V_2 -> V_35 ; V_4 = V_78 , V_29 ++ ) {
V_77 -= 2 ;
V_78 = F_4 ( V_2 , V_77 ) ;
if ( V_78 <= V_4 ||
V_78 > V_11 -> V_36 ||
V_78 & 1 )
goto V_81;
V_79 = V_78 - V_4 ;
if ( V_2 -> type != V_37 &&
V_2 -> type != V_13 )
continue;
V_80 = F_6 ( V_2 , V_4 ) + 1 ;
if ( V_80 >= V_79 )
goto V_81;
}
F_46 ( V_65 , & V_2 -> V_46 ) ;
F_47 ( & V_2 -> V_68 ) ;
return V_2 ;
V_81:
F_26 ( V_75 , & V_2 -> V_46 ) ;
F_46 ( V_65 , & V_2 -> V_46 ) ;
F_47 ( & V_2 -> V_68 ) ;
F_24 ( V_2 ) ;
return F_45 ( - V_85 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
}
struct V_1 * F_49 ( struct V_10 * V_11 , T_5 V_47 )
{
struct V_1 * V_2 ;
struct V_6 * * V_86 ;
int V_29 ;
F_33 ( & V_11 -> V_69 ) ;
V_2 = F_28 ( V_11 , V_47 ) ;
F_34 ( & V_11 -> V_69 ) ;
F_43 ( V_2 ) ;
V_2 = F_29 ( V_11 , V_47 ) ;
if ( ! V_2 )
return F_45 ( - V_82 ) ;
if ( F_37 ( V_75 , & V_2 -> V_46 ) ) {
F_24 ( V_2 ) ;
return F_45 ( - V_85 ) ;
}
V_86 = V_2 -> V_6 ;
memset ( F_2 ( * V_86 ) + V_2 -> V_7 , 0 ,
F_50 ( ( int ) V_87 , ( int ) V_11 -> V_36 ) ) ;
F_9 ( * V_86 ) ;
F_3 ( * V_86 ) ;
for ( V_29 = 1 ; V_29 < V_11 -> V_63 ; V_29 ++ ) {
memset ( F_2 ( * ++ V_86 ) , 0 , V_87 ) ;
F_9 ( * V_86 ) ;
F_3 ( * V_86 ) ;
}
F_46 ( V_65 , & V_2 -> V_46 ) ;
F_47 ( & V_2 -> V_68 ) ;
return V_2 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_51 ( & V_2 -> V_66 ) ;
F_15 ( V_67 , L_14 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 , F_42 ( & V_2 -> V_66 ) ) ;
}
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_10 * V_11 = V_2 -> V_11 ;
int V_29 ;
F_15 ( V_67 , L_15 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 , F_42 ( & V_2 -> V_66 ) ) ;
F_43 ( ! F_42 ( & V_2 -> V_66 ) ) ;
if ( ! F_52 ( & V_2 -> V_66 , & V_11 -> V_69 ) )
return;
for ( V_29 = 0 ; V_29 < V_11 -> V_63 ; V_29 ++ ) {
if ( ! V_2 -> V_6 [ V_29 ] )
continue;
F_53 ( V_2 -> V_6 [ V_29 ] ) ;
}
if ( F_37 ( V_45 , & V_2 -> V_46 ) ) {
F_41 ( V_2 ) ;
F_34 ( & V_11 -> V_69 ) ;
F_54 ( V_2 ) ;
F_48 ( V_2 ) ;
return;
}
F_34 ( & V_11 -> V_69 ) ;
}
}
