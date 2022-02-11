static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_8 ;
int V_9 = 0 ;
F_2 ( ! F_3 ( & V_7 -> V_10 . V_11 ) ) ;
F_4 (connector, dev) {
if ( V_8 -> V_12 && V_8 -> V_12 -> V_2 == V_2 ) {
if ( V_4 != NULL && V_9 < V_5 )
* ( V_4 ++ ) = V_8 ;
V_9 ++ ;
}
}
return V_9 ;
}
int F_5 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_17 * V_19 ,
const struct V_17 * V_20 ,
unsigned int V_21 ,
int V_22 ,
int V_23 ,
bool V_24 ,
bool V_25 ,
bool * V_26 )
{
int V_27 , V_28 ;
if ( ! V_16 ) {
* V_26 = false ;
return 0 ;
}
if ( F_2 ( ! V_2 ) ) {
* V_26 = false ;
return 0 ;
}
if ( ! V_2 -> V_29 && ! V_25 ) {
F_6 ( L_1 ) ;
return - V_30 ;
}
F_7 ( V_18 , V_16 -> V_31 << 16 , V_16 -> V_32 << 16 , V_21 ) ;
V_27 = F_8 ( V_18 , V_19 , V_22 , V_23 ) ;
V_28 = F_9 ( V_18 , V_19 , V_22 , V_23 ) ;
if ( V_27 < 0 || V_28 < 0 ) {
F_6 ( L_2 ) ;
F_10 ( L_3 , V_18 , true ) ;
F_10 ( L_4 , V_19 , false ) ;
return - V_33 ;
}
* V_26 = F_11 ( V_18 , V_19 , V_20 , V_27 , V_28 ) ;
F_12 ( V_18 , V_16 -> V_31 << 16 , V_16 -> V_32 << 16 , V_21 ) ;
if ( ! * V_26 )
return 0 ;
if ( ! V_24 && ! F_13 ( V_19 , V_20 ) ) {
F_6 ( L_5 ) ;
F_10 ( L_4 , V_19 , false ) ;
F_10 ( L_6 , V_20 , false ) ;
return - V_30 ;
}
return 0 ;
}
int F_14 ( struct V_13 * V_14 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_34 , int V_35 ,
unsigned int V_36 , unsigned int V_37 ,
T_1 V_38 , T_1 V_39 ,
T_1 V_40 , T_1 V_41 )
{
struct V_42 V_43 = {
. V_2 = V_2 ,
. V_16 = V_16 ,
. V_44 = & V_2 -> V_44 ,
. V_45 = V_38 >> 16 ,
. V_46 = V_39 >> 16 ,
} ;
struct V_17 V_18 = {
. V_47 = V_38 ,
. y1 = V_39 ,
. V_48 = V_38 + V_40 ,
. V_49 = V_39 + V_41 ,
} ;
struct V_17 V_19 = {
. V_47 = V_34 ,
. y1 = V_35 ,
. V_48 = V_34 + V_36 ,
. V_49 = V_35 + V_37 ,
} ;
const struct V_17 V_20 = {
. V_48 = V_2 -> V_44 . V_50 ,
. V_49 = V_2 -> V_44 . V_51 ,
} ;
struct V_3 * * V_4 ;
int V_5 , V_52 ;
bool V_26 ;
V_52 = F_5 ( V_14 , V_2 , V_16 ,
& V_18 , & V_19 , & V_20 ,
F_15 ( V_53 ) ,
V_54 ,
V_54 ,
false , false , & V_26 ) ;
if ( V_52 )
return V_52 ;
if ( ! V_26 )
return V_14 -> V_55 -> V_56 ( V_14 ) ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_16 ( V_5 == 0 ) ;
V_4 = F_17 ( V_5 * sizeof( * V_4 ) ,
V_57 ) ;
if ( ! V_4 )
return - V_58 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_43 . V_59 = V_4 ;
V_43 . V_5 = V_5 ;
V_52 = V_2 -> V_55 -> V_60 ( & V_43 ) ;
F_18 ( V_4 ) ;
return V_52 ;
}
int F_19 ( struct V_13 * V_14 )
{
return - V_30 ;
}
void F_20 ( struct V_13 * V_14 )
{
F_21 ( V_14 ) ;
F_18 ( V_14 ) ;
}
static struct V_13 * F_22 ( struct V_6 * V_7 )
{
struct V_13 * V_61 ;
int V_52 ;
V_61 = F_17 ( sizeof( * V_61 ) , V_57 ) ;
if ( V_61 == NULL ) {
F_6 ( L_7 ) ;
return NULL ;
}
V_61 -> V_62 = true ;
V_52 = F_23 ( V_7 , V_61 , 0 ,
& V_63 ,
V_64 ,
F_24 ( V_64 ) ,
V_65 , NULL ) ;
if ( V_52 ) {
F_18 ( V_61 ) ;
V_61 = NULL ;
}
return V_61 ;
}
int F_25 ( struct V_6 * V_7 , struct V_1 * V_2 ,
const struct V_66 * V_55 )
{
struct V_13 * V_61 ;
V_61 = F_22 ( V_7 ) ;
return F_26 ( V_7 , V_2 , V_61 , NULL , V_55 ,
NULL ) ;
}
int F_27 ( struct V_13 * V_14 ,
struct V_67 * V_68 ,
struct V_15 * V_69 )
{
const struct V_70 * V_71 ;
struct V_1 * V_2 [ 2 ] ;
const struct V_72 * V_73 [ 2 ] ;
int V_74 , V_52 = 0 ;
V_71 = V_14 -> V_75 ;
V_2 [ 0 ] = V_14 -> V_2 ;
V_2 [ 1 ] = V_2 [ 0 ] != V_68 -> V_2 ? V_68 -> V_2 : NULL ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ )
V_73 [ V_74 ] = V_2 [ V_74 ] ? V_2 [ V_74 ] -> V_75 : NULL ;
if ( V_71 -> V_76 ) {
V_52 = V_71 -> V_76 ( V_14 , V_68 ) ;
if ( V_52 )
goto V_77;
}
if ( V_71 -> V_78 && V_68 -> V_16 &&
V_68 -> V_16 != V_69 ) {
V_52 = V_71 -> V_78 ( V_14 ,
V_68 ) ;
if ( V_52 )
goto V_77;
}
F_28 ( V_14 -> V_79 , V_68 ) ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
if ( V_73 [ V_74 ] && V_73 [ V_74 ] -> V_80 )
V_73 [ V_74 ] -> V_80 ( V_2 [ V_74 ] , V_2 [ V_74 ] -> V_79 ) ;
}
if ( F_29 ( V_14 , V_68 ) &&
V_71 -> V_81 )
V_71 -> V_81 ( V_14 , V_68 ) ;
else
V_71 -> V_82 ( V_14 , V_68 ) ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
if ( V_73 [ V_74 ] && V_73 [ V_74 ] -> V_83 )
V_73 [ V_74 ] -> V_83 ( V_2 [ V_74 ] , V_2 [ V_74 ] -> V_79 ) ;
}
if ( V_14 -> V_79 -> V_16 == V_69 )
goto V_77;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
if ( ! V_2 [ V_74 ] )
continue;
if ( V_2 [ V_74 ] -> V_84 == V_14 )
continue;
V_52 = F_30 ( V_2 [ V_74 ] ) ;
if ( V_52 == 0 ) {
F_31 ( V_2 [ V_74 ] ) ;
F_32 ( V_2 [ V_74 ] ) ;
}
V_52 = 0 ;
}
if ( V_71 -> V_85 )
V_71 -> V_85 ( V_14 , V_68 ) ;
V_77:
if ( V_68 ) {
if ( V_14 -> V_55 -> V_86 )
V_14 -> V_55 -> V_86 ( V_14 , V_68 ) ;
else
F_33 ( V_14 , V_68 ) ;
}
return V_52 ;
}
int F_34 ( struct V_13 * V_14 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_34 , int V_35 ,
unsigned int V_36 , unsigned int V_37 ,
T_1 V_38 , T_1 V_39 ,
T_1 V_40 , T_1 V_41 )
{
struct V_67 * V_68 ;
if ( V_14 -> V_55 -> V_87 )
V_68 = V_14 -> V_55 -> V_87 ( V_14 ) ;
else {
if ( ! V_14 -> V_79 )
F_35 ( V_14 ) ;
V_68 = F_36 ( V_14 ) ;
}
if ( ! V_68 )
return - V_58 ;
V_68 -> V_14 = V_14 ;
V_68 -> V_2 = V_2 ;
F_37 ( V_68 , V_16 ) ;
V_68 -> V_34 = V_34 ;
V_68 -> V_35 = V_35 ;
V_68 -> V_37 = V_37 ;
V_68 -> V_36 = V_36 ;
V_68 -> V_38 = V_38 ;
V_68 -> V_39 = V_39 ;
V_68 -> V_41 = V_41 ;
V_68 -> V_40 = V_40 ;
return F_27 ( V_14 , V_68 , V_14 -> V_16 ) ;
}
int F_38 ( struct V_13 * V_14 )
{
struct V_67 * V_68 ;
if ( ! V_14 -> V_2 )
return 0 ;
if ( V_14 -> V_55 -> V_87 )
V_68 = V_14 -> V_55 -> V_87 ( V_14 ) ;
else {
if ( ! V_14 -> V_79 )
F_35 ( V_14 ) ;
V_68 = F_36 ( V_14 ) ;
}
if ( ! V_68 )
return - V_58 ;
V_68 -> V_14 = V_14 ;
V_68 -> V_2 = NULL ;
F_37 ( V_68 , NULL ) ;
return F_27 ( V_14 , V_68 , V_14 -> V_16 ) ;
}
