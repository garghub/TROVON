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
F_19 ( V_24 , L_5 , V_30 ) ;
if ( V_29 && V_2 -> type == V_37 ) {
int V_38 ;
if ( V_2 -> V_11 -> V_14 & V_15 )
V_38 = ( F_6 ( V_2 , V_30 ) | 1 ) + 1 ;
else
V_38 = V_2 -> V_11 -> V_16 + 1 ;
F_19 ( V_24 , L_6 ,
V_38 , F_6 ( V_2 , V_30 ) ) ;
F_1 ( V_2 , & V_28 , V_30 + V_38 , 4 ) ;
F_19 ( V_24 , L_7 , F_18 ( V_28 ) ) ;
} else if ( V_29 && V_2 -> type == V_13 ) {
int V_38 ;
V_38 = F_6 ( V_2 , V_30 ) ;
F_19 ( V_24 , L_8 , V_38 ) ;
}
}
F_19 ( V_24 , L_9 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_1 * V_38 ;
T_4 V_28 ;
V_11 = V_2 -> V_11 ;
if ( V_2 -> V_33 ) {
V_38 = F_21 ( V_11 , V_2 -> V_33 ) ;
if ( F_22 ( V_38 ) )
return;
V_38 -> V_32 = V_2 -> V_32 ;
V_28 = F_23 ( V_38 -> V_32 ) ;
F_8 ( V_38 , & V_28 , F_24 ( struct V_26 , V_32 ) , 4 ) ;
F_25 ( V_38 ) ;
} else if ( V_2 -> type == V_13 )
V_11 -> V_39 = V_2 -> V_32 ;
if ( V_2 -> V_32 ) {
V_38 = F_21 ( V_11 , V_2 -> V_32 ) ;
if ( F_22 ( V_38 ) )
return;
V_38 -> V_33 = V_2 -> V_33 ;
V_28 = F_23 ( V_38 -> V_33 ) ;
F_8 ( V_38 , & V_28 , F_24 ( struct V_26 , V_33 ) , 4 ) ;
F_25 ( V_38 ) ;
} else if ( V_2 -> type == V_13 )
V_11 -> V_40 = V_2 -> V_33 ;
if ( ! V_2 -> V_33 && ! V_2 -> V_32 ) {
F_26 ( V_41 L_10 ) ;
}
if ( ! V_2 -> V_42 ) {
V_11 -> V_43 = 0 ;
V_11 -> V_44 = 0 ;
}
F_27 ( V_45 , & V_2 -> V_46 ) ;
}
static inline int F_28 ( T_5 V_47 )
{
V_47 = ( V_47 >> 16 ) + V_47 ;
V_47 += V_47 >> 8 ;
return V_47 & ( V_48 - 1 ) ;
}
struct V_1 * F_29 ( struct V_10 * V_11 , T_5 V_28 )
{
struct V_1 * V_2 ;
if ( V_28 >= V_11 -> V_49 ) {
F_30 ( L_11 , V_28 ) ;
return NULL ;
}
for ( V_2 = V_11 -> V_50 [ F_28 ( V_28 ) ] ;
V_2 ; V_2 = V_2 -> V_51 ) {
if ( V_2 -> V_31 == V_28 ) {
return V_2 ;
}
}
return NULL ;
}
static struct V_1 * F_31 ( struct V_10 * V_11 , T_5 V_28 )
{
struct V_52 * V_53 ;
struct V_1 * V_2 , * V_54 ;
struct V_55 * V_56 ;
struct V_6 * V_6 ;
int V_57 , V_58 , V_29 , V_59 ;
T_6 V_4 ;
if ( V_28 >= V_11 -> V_49 ) {
F_30 ( L_11 , V_28 ) ;
return NULL ;
}
V_53 = V_11 -> V_60 -> V_61 ;
V_57 = sizeof( struct V_1 ) + V_11 -> V_62 *
sizeof( struct V_6 * ) ;
V_2 = F_32 ( V_57 , V_63 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_31 = V_28 ;
F_27 ( V_64 , & V_2 -> V_46 ) ;
F_33 ( & V_2 -> V_65 , 1 ) ;
F_15 ( V_66 , L_12 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_67 ) ;
F_35 ( & V_11 -> V_68 ) ;
V_54 = F_29 ( V_11 , V_28 ) ;
if ( ! V_54 ) {
V_59 = F_28 ( V_28 ) ;
V_2 -> V_51 = V_11 -> V_50 [ V_59 ] ;
V_11 -> V_50 [ V_59 ] = V_2 ;
V_11 -> V_69 ++ ;
} else {
F_36 ( & V_11 -> V_68 ) ;
F_37 ( V_2 ) ;
F_38 ( V_54 -> V_67 , ! F_39 ( V_64 , & V_54 -> V_46 ) ) ;
return V_54 ;
}
F_36 ( & V_11 -> V_68 ) ;
V_56 = V_11 -> V_60 -> V_70 ;
V_4 = ( T_6 ) V_28 * V_11 -> V_36 ;
V_58 = V_4 >> V_71 ;
V_2 -> V_7 = V_4 & ~ V_72 ;
for ( V_29 = 0 ; V_29 < V_11 -> V_62 ; V_29 ++ ) {
V_6 = F_40 ( V_56 , V_58 ++ , NULL ) ;
if ( F_22 ( V_6 ) )
goto V_73;
if ( F_41 ( V_6 ) ) {
F_42 ( V_6 ) ;
goto V_73;
}
F_42 ( V_6 ) ;
V_2 -> V_6 [ V_29 ] = V_6 ;
}
return V_2 ;
V_73:
F_27 ( V_74 , & V_2 -> V_46 ) ;
return V_2 ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_1 * * V_75 ;
F_15 ( V_66 , L_13 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 , F_44 ( & V_2 -> V_65 ) ) ;
for ( V_75 = & V_2 -> V_11 -> V_50 [ F_28 ( V_2 -> V_31 ) ] ;
* V_75 && * V_75 != V_2 ; V_75 = & ( * V_75 ) -> V_51 )
;
F_45 ( ! * V_75 ) ;
* V_75 = V_2 -> V_51 ;
V_2 -> V_11 -> V_69 -- ;
}
struct V_1 * F_21 ( struct V_10 * V_11 , T_5 V_47 )
{
struct V_1 * V_2 ;
struct V_26 * V_27 ;
int V_29 , V_76 , V_4 , V_77 ;
int V_78 , V_79 ;
F_35 ( & V_11 -> V_68 ) ;
V_2 = F_29 ( V_11 , V_47 ) ;
if ( V_2 ) {
F_46 ( V_2 ) ;
F_36 ( & V_11 -> V_68 ) ;
F_38 ( V_2 -> V_67 , ! F_39 ( V_64 , & V_2 -> V_46 ) ) ;
if ( F_39 ( V_74 , & V_2 -> V_46 ) )
goto V_80;
return V_2 ;
}
F_36 ( & V_11 -> V_68 ) ;
V_2 = F_31 ( V_11 , V_47 ) ;
if ( ! V_2 )
return F_47 ( - V_81 ) ;
if ( F_39 ( V_74 , & V_2 -> V_46 ) )
goto V_80;
if ( ! F_39 ( V_64 , & V_2 -> V_46 ) )
return V_2 ;
V_27 = (struct V_26 * ) ( F_2 ( V_2 -> V_6 [ 0 ] ) + V_2 -> V_7 ) ;
V_2 -> V_33 = F_18 ( V_27 -> V_33 ) ;
V_2 -> V_32 = F_18 ( V_27 -> V_32 ) ;
V_2 -> V_35 = F_5 ( V_27 -> V_35 ) ;
V_2 -> type = V_27 -> type ;
V_2 -> V_34 = V_27 -> V_34 ;
F_3 ( V_2 -> V_6 [ 0 ] ) ;
switch ( V_2 -> type ) {
case V_82 :
case V_83 :
if ( V_2 -> V_34 != 0 )
goto V_80;
break;
case V_13 :
if ( V_2 -> V_34 != 1 )
goto V_80;
break;
case V_37 :
if ( V_2 -> V_34 <= 1 || V_2 -> V_34 > V_11 -> V_44 )
goto V_80;
break;
default:
goto V_80;
}
V_76 = V_11 -> V_36 - 2 ;
V_4 = F_4 ( V_2 , V_76 ) ;
if ( V_4 != sizeof( struct V_26 ) )
goto V_80;
for ( V_29 = 1 ; V_29 <= V_2 -> V_35 ; V_4 = V_77 , V_29 ++ ) {
V_76 -= 2 ;
V_77 = F_4 ( V_2 , V_76 ) ;
if ( V_77 <= V_4 ||
V_77 > V_11 -> V_36 ||
V_77 & 1 )
goto V_80;
V_78 = V_77 - V_4 ;
if ( V_2 -> type != V_37 &&
V_2 -> type != V_13 )
continue;
V_79 = F_6 ( V_2 , V_4 ) + 1 ;
if ( V_79 >= V_78 )
goto V_80;
}
F_48 ( V_64 , & V_2 -> V_46 ) ;
F_49 ( & V_2 -> V_67 ) ;
return V_2 ;
V_80:
F_27 ( V_74 , & V_2 -> V_46 ) ;
F_48 ( V_64 , & V_2 -> V_46 ) ;
F_49 ( & V_2 -> V_67 ) ;
F_25 ( V_2 ) ;
return F_47 ( - V_84 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
}
struct V_1 * F_51 ( struct V_10 * V_11 , T_5 V_47 )
{
struct V_1 * V_2 ;
struct V_6 * * V_85 ;
int V_29 ;
F_35 ( & V_11 -> V_68 ) ;
V_2 = F_29 ( V_11 , V_47 ) ;
F_36 ( & V_11 -> V_68 ) ;
if ( V_2 ) {
F_52 ( L_14 , V_47 ) ;
F_53 ( 1 ) ;
return V_2 ;
}
V_2 = F_31 ( V_11 , V_47 ) ;
if ( ! V_2 )
return F_47 ( - V_81 ) ;
if ( F_39 ( V_74 , & V_2 -> V_46 ) ) {
F_25 ( V_2 ) ;
return F_47 ( - V_84 ) ;
}
V_85 = V_2 -> V_6 ;
memset ( F_2 ( * V_85 ) + V_2 -> V_7 , 0 ,
F_54 ( ( int ) V_86 , ( int ) V_11 -> V_36 ) ) ;
F_9 ( * V_85 ) ;
F_3 ( * V_85 ) ;
for ( V_29 = 1 ; V_29 < V_11 -> V_62 ; V_29 ++ ) {
memset ( F_2 ( * ++ V_85 ) , 0 , V_86 ) ;
F_9 ( * V_85 ) ;
F_3 ( * V_85 ) ;
}
F_48 ( V_64 , & V_2 -> V_46 ) ;
F_49 ( & V_2 -> V_67 ) ;
return V_2 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_55 ( & V_2 -> V_65 ) ;
F_15 ( V_66 , L_15 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 ,
F_44 ( & V_2 -> V_65 ) ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_10 * V_11 = V_2 -> V_11 ;
int V_29 ;
F_15 ( V_66 , L_16 ,
V_2 -> V_11 -> V_28 , V_2 -> V_31 ,
F_44 ( & V_2 -> V_65 ) ) ;
F_45 ( ! F_44 ( & V_2 -> V_65 ) ) ;
if ( ! F_56 ( & V_2 -> V_65 , & V_11 -> V_68 ) )
return;
for ( V_29 = 0 ; V_29 < V_11 -> V_62 ; V_29 ++ ) {
if ( ! V_2 -> V_6 [ V_29 ] )
continue;
F_57 ( V_2 -> V_6 [ V_29 ] ) ;
}
if ( F_39 ( V_45 , & V_2 -> V_46 ) ) {
F_43 ( V_2 ) ;
F_36 ( & V_11 -> V_68 ) ;
F_58 ( V_2 ) ;
F_50 ( V_2 ) ;
return;
}
F_36 ( & V_11 -> V_68 ) ;
}
}
