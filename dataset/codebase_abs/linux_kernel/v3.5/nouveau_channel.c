static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ? V_5 : V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
int V_12 ;
V_12 = F_2 ( V_8 , 65536 , 0 , V_3 , 0 , 0 , NULL , & V_2 -> V_13 ) ;
if ( V_12 )
goto V_14;
V_12 = F_3 ( V_2 -> V_13 , V_3 ) ;
if ( V_12 )
goto V_14;
V_12 = F_4 ( V_2 -> V_13 ) ;
if ( V_12 )
goto V_14;
V_2 -> V_15 = V_2 -> V_13 -> V_16 . V_17 ;
if ( V_10 -> V_18 >= V_19 ) {
V_12 = F_5 ( V_2 -> V_13 , V_2 -> V_20 ,
& V_2 -> V_21 ) ;
if ( V_12 )
goto V_14;
if ( V_10 -> V_18 < V_22 ) {
V_12 = F_6 ( V_2 ,
V_23 , 0 ,
( 1ULL << 40 ) ,
V_24 ,
V_25 ,
& V_2 -> V_26 ) ;
}
V_2 -> V_15 = V_2 -> V_21 . V_17 ;
} else
if ( V_2 -> V_13 -> V_16 . V_3 . V_27 == V_28 ) {
V_12 = F_6 ( V_2 , V_23 , 0 ,
V_10 -> V_29 . V_30 ,
V_24 ,
V_31 ,
& V_2 -> V_26 ) ;
} else
if ( V_10 -> V_18 != V_32 ) {
V_12 = F_6 ( V_2 , V_23 , 0 ,
V_10 -> V_33 ,
V_24 ,
V_34 ,
& V_2 -> V_26 ) ;
} else {
V_12 = F_6 ( V_2 , V_23 ,
F_7 ( V_8 -> V_35 , 1 ) ,
V_10 -> V_33 ,
V_24 ,
V_36 ,
& V_2 -> V_26 ) ;
}
V_14:
if ( V_12 ) {
F_8 ( V_8 , L_1 , V_12 ) ;
F_9 ( V_2 -> V_13 , & V_2 -> V_21 ) ;
F_10 ( NULL , & V_2 -> V_26 ) ;
if ( V_2 -> V_13 ) {
F_11 ( V_2 -> V_13 ) ;
F_12 ( NULL , & V_2 -> V_13 ) ;
}
}
return 0 ;
}
int
F_13 ( struct V_7 * V_8 , struct V_1 * * V_37 ,
struct V_38 * V_39 ,
T_2 V_40 , T_2 V_41 )
{
struct V_42 * V_43 = F_14 ( V_8 , V_44 ) ;
struct V_45 * V_46 = F_14 ( V_8 , V_47 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_48 * V_49 = V_48 ( V_39 ) ;
struct V_1 * V_2 ;
unsigned long V_50 ;
int V_12 , V_51 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_41 = V_41 ;
F_16 ( & V_2 -> V_54 ) ;
F_17 ( & V_2 -> V_55 , 1 ) ;
F_18 ( & V_2 -> V_56 ) ;
F_19 ( & V_2 -> V_56 ) ;
F_20 ( & V_10 -> V_57 . V_58 , V_50 ) ;
for ( V_2 -> V_59 = 0 ; V_2 -> V_59 < V_46 -> V_57 ; V_2 -> V_59 ++ ) {
if ( ! V_10 -> V_57 . V_60 [ V_2 -> V_59 ] ) {
F_21 ( V_2 , & V_10 -> V_57 . V_60 [ V_2 -> V_59 ] ) ;
break;
}
}
F_22 ( & V_10 -> V_57 . V_58 , V_50 ) ;
if ( V_2 -> V_59 == V_46 -> V_57 ) {
F_23 ( & V_2 -> V_56 ) ;
F_24 ( V_2 ) ;
return - V_61 ;
}
F_25 ( V_8 , L_2 , V_2 -> V_59 ) ;
V_12 = F_26 ( V_2 , V_40 , V_41 ) ;
if ( V_12 ) {
F_8 ( V_8 , L_3 , V_12 ) ;
F_27 ( & V_2 ) ;
return V_12 ;
}
V_12 = F_28 ( V_2 ) ;
if ( V_12 ) {
F_8 ( V_8 , L_4 , V_12 ) ;
F_27 ( & V_2 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_8 ( V_8 , L_5 , V_12 ) ;
F_27 ( & V_2 ) ;
return V_12 ;
}
F_29 ( V_2 ) ;
V_2 -> V_62 = 0x40 ;
V_2 -> V_63 = 0x44 ;
if ( V_10 -> V_18 >= V_19 )
V_2 -> V_64 = 0x60 ;
V_12 = V_46 -> V_65 . V_66 ( V_2 , V_47 ) ;
if ( V_12 ) {
F_27 ( & V_2 ) ;
return V_12 ;
}
V_12 = F_30 ( V_2 , V_67 ) ;
if ( V_12 ) {
F_27 ( & V_2 ) ;
return V_12 ;
}
for ( V_51 = 0 ; V_51 < V_67 ; V_51 ++ )
F_31 ( V_2 , 0x00000000 ) ;
V_12 = F_32 ( V_2 , V_68 , F_33 ( V_8 ) ) ;
if ( V_12 ) {
F_27 ( & V_2 ) ;
return V_12 ;
}
if ( V_10 -> V_18 < V_22 ) {
V_12 = F_30 ( V_2 , 2 ) ;
if ( V_12 ) {
F_27 ( & V_2 ) ;
return V_12 ;
}
F_34 ( V_2 , V_69 , V_70 , 1 ) ;
F_31 ( V_2 , V_68 ) ;
F_35 ( V_2 ) ;
}
F_35 ( V_2 ) ;
V_12 = V_43 -> V_66 ( V_2 , V_44 ) ;
if ( V_12 ) {
F_27 ( & V_2 ) ;
return V_12 ;
}
F_36 ( V_2 ) ;
F_25 ( V_8 , L_6 , V_2 -> V_59 ) ;
if ( V_49 ) {
F_37 ( & V_49 -> V_58 ) ;
F_38 ( & V_2 -> V_71 , & V_49 -> V_57 ) ;
F_39 ( & V_49 -> V_58 ) ;
}
* V_37 = V_2 ;
return 0 ;
}
struct V_1 *
F_40 ( struct V_1 * V_54 )
{
struct V_1 * V_2 = NULL ;
if ( F_41 ( V_54 && F_42 ( & V_54 -> V_55 ) ) )
F_21 ( V_54 , & V_2 ) ;
return V_2 ;
}
struct V_1 *
F_43 ( struct V_38 * V_39 , int V_59 )
{
struct V_48 * V_49 = V_48 ( V_39 ) ;
struct V_1 * V_2 ;
F_37 ( & V_49 -> V_58 ) ;
F_44 (chan, &fpriv->channels, list) {
if ( V_2 -> V_59 == V_59 ) {
V_2 = F_40 ( V_2 ) ;
F_39 ( & V_49 -> V_58 ) ;
F_19 ( & V_2 -> V_56 ) ;
return V_2 ;
}
}
F_39 ( & V_49 -> V_58 ) ;
return F_45 ( - V_72 ) ;
}
void
F_46 ( struct V_1 * * V_73 )
{
struct V_1 * V_2 = * V_73 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_50 ;
int V_51 ;
if ( F_41 ( ! F_47 ( & V_2 -> V_55 ) ) ) {
F_21 ( NULL , V_73 ) ;
return;
}
F_25 ( V_8 , L_7 , V_2 -> V_59 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
for ( V_51 = V_74 - 1 ; V_51 >= 0 ; V_51 -- ) {
if ( V_2 -> V_75 [ V_51 ] )
V_10 -> V_76 [ V_51 ] -> F_50 ( V_2 , V_51 ) ;
}
F_20 ( & V_10 -> V_57 . V_58 , V_50 ) ;
F_21 ( NULL , & V_10 -> V_57 . V_60 [ V_2 -> V_59 ] ) ;
F_22 ( & V_10 -> V_57 . V_58 , V_50 ) ;
F_10 ( NULL , & V_2 -> V_26 ) ;
if ( V_2 -> V_13 ) {
F_9 ( V_2 -> V_13 , & V_2 -> V_21 ) ;
F_11 ( V_2 -> V_13 ) ;
F_51 ( V_2 -> V_13 ) ;
F_12 ( NULL , & V_2 -> V_13 ) ;
}
F_52 ( NULL , & V_2 -> V_77 , V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_21 ( NULL , V_73 ) ;
}
void
F_27 ( struct V_1 * * V_73 )
{
F_23 ( & ( * V_73 ) -> V_56 ) ;
F_46 ( V_73 ) ;
}
static void
F_55 ( struct V_78 * V_54 )
{
struct V_1 * V_2 =
F_56 ( V_54 , struct V_1 , V_54 ) ;
F_24 ( V_2 ) ;
}
void
F_21 ( struct V_1 * V_2 ,
struct V_1 * * V_73 )
{
if ( V_2 )
F_57 ( & V_2 -> V_54 ) ;
if ( * V_73 )
F_58 ( & ( * V_73 ) -> V_54 , F_55 ) ;
* V_73 = V_2 ;
}
int
F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_79 * V_43 = NULL ;
int V_12 ;
V_12 = F_59 ( V_2 , & V_43 ) ;
if ( ! V_12 ) {
V_12 = F_60 ( V_43 , false , false ) ;
F_61 ( & V_43 ) ;
}
if ( V_12 )
F_8 ( V_8 , L_8 , V_2 -> V_59 ) ;
return V_12 ;
}
void
F_62 ( struct V_7 * V_8 , struct V_38 * V_39 )
{
struct V_45 * V_46 = F_14 ( V_8 , V_47 ) ;
struct V_1 * V_2 ;
int V_51 ;
if ( ! V_46 )
return;
F_25 ( V_8 , L_9 ) ;
for ( V_51 = 0 ; V_51 < V_46 -> V_57 ; V_51 ++ ) {
V_2 = F_43 ( V_39 , V_51 ) ;
if ( F_63 ( V_2 ) )
continue;
F_64 ( & V_2 -> V_71 ) ;
F_65 ( & V_2 -> V_55 ) ;
F_27 ( & V_2 ) ;
}
}
static int
F_66 ( struct V_7 * V_8 , void * V_80 ,
struct V_38 * V_39 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_81 * V_82 = V_80 ;
struct V_1 * V_2 ;
int V_12 ;
if ( ! V_10 -> V_76 [ V_83 ] )
return - V_61 ;
if ( V_82 -> V_84 == ~ 0 || V_82 -> V_85 == ~ 0 )
return - V_72 ;
V_12 = F_13 ( V_8 , & V_2 , V_39 ,
V_82 -> V_84 ,
V_82 -> V_85 ) ;
if ( V_12 )
return V_12 ;
V_82 -> V_86 = V_2 -> V_59 ;
if ( V_4 == 0 ) {
if ( V_2 -> V_87 . V_88 )
V_82 -> V_89 = V_90 |
V_91 ;
else if ( V_2 -> V_13 -> V_16 . V_3 . V_27 == V_92 )
V_82 -> V_89 = V_90 ;
else
V_82 -> V_89 = V_91 ;
} else {
V_82 -> V_89 = V_90 ;
}
if ( V_10 -> V_18 < V_22 ) {
V_82 -> V_93 [ 0 ] . V_94 = 0x00000000 ;
V_82 -> V_93 [ 0 ] . V_95 = 0x0000 ;
V_82 -> V_93 [ 1 ] . V_94 = V_68 ;
V_82 -> V_93 [ 1 ] . V_95 = V_96 ;
V_82 -> V_97 = 2 ;
}
V_12 = F_67 ( V_39 , V_2 -> V_98 -> V_99 ,
& V_82 -> V_100 ) ;
if ( V_12 == 0 )
F_68 ( & V_2 -> V_55 ) ;
F_27 ( & V_2 ) ;
return V_12 ;
}
static int
F_69 ( struct V_7 * V_8 , void * V_80 ,
struct V_38 * V_39 )
{
struct V_101 * V_102 = V_80 ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_39 , V_102 -> V_86 ) ;
if ( F_63 ( V_2 ) )
return F_70 ( V_2 ) ;
F_64 ( & V_2 -> V_71 ) ;
F_65 ( & V_2 -> V_55 ) ;
F_27 ( & V_2 ) ;
return 0 ;
}
