static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_8 ;
struct V_9 V_10 ;
int V_11 = 0 ;
F_2 ( ! F_3 ( & V_7 -> V_12 . V_13 ) ) ;
F_4 ( V_7 , & V_10 ) ;
F_5 (connector, &conn_iter) {
if ( V_8 -> V_14 && V_8 -> V_14 -> V_2 == V_2 ) {
if ( V_4 != NULL && V_11 < V_5 )
* ( V_4 ++ ) = V_8 ;
V_11 ++ ;
}
}
F_6 ( & V_10 ) ;
return V_11 ;
}
int F_7 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
int V_19 ,
int V_20 ,
bool V_21 ,
bool V_22 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_23 * V_24 = V_16 -> V_24 ;
struct V_17 * V_25 = & V_16 -> V_25 ;
struct V_17 * V_26 = & V_16 -> V_26 ;
unsigned int V_27 = V_16 -> V_27 ;
int V_28 , V_29 ;
* V_25 = F_8 ( V_16 ) ;
* V_26 = F_9 ( V_16 ) ;
if ( ! V_24 ) {
V_16 -> V_30 = false ;
return 0 ;
}
if ( F_2 ( ! V_2 ) ) {
V_16 -> V_30 = false ;
return 0 ;
}
if ( ! V_2 -> V_31 && ! V_22 ) {
F_10 ( L_1 ) ;
return - V_32 ;
}
F_11 ( V_25 , V_24 -> V_33 << 16 , V_24 -> V_34 << 16 , V_27 ) ;
V_28 = F_12 ( V_25 , V_26 , V_19 , V_20 ) ;
V_29 = F_13 ( V_25 , V_26 , V_19 , V_20 ) ;
if ( V_28 < 0 || V_29 < 0 ) {
F_10 ( L_2 ) ;
F_14 ( L_3 , & V_16 -> V_25 , true ) ;
F_14 ( L_4 , & V_16 -> V_26 , false ) ;
return - V_35 ;
}
V_16 -> V_30 = F_15 ( V_25 , V_26 , V_18 , V_28 , V_29 ) ;
F_16 ( V_25 , V_24 -> V_33 << 16 , V_24 -> V_34 << 16 , V_27 ) ;
if ( ! V_16 -> V_30 )
return 0 ;
if ( ! V_21 && ! F_17 ( V_26 , V_18 ) ) {
F_10 ( L_5 ) ;
F_14 ( L_4 , V_26 , false ) ;
F_14 ( L_6 , V_18 , false ) ;
return - V_32 ;
}
return 0 ;
}
int F_18 ( struct V_36 * V_37 ,
struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_17 * V_25 ,
struct V_17 * V_26 ,
const struct V_17 * V_18 ,
unsigned int V_27 ,
int V_19 ,
int V_20 ,
bool V_21 ,
bool V_22 ,
bool * V_30 )
{
struct V_15 V_16 = {
. V_37 = V_37 ,
. V_2 = V_2 ,
. V_24 = V_24 ,
. V_38 = V_25 -> V_39 ,
. V_40 = V_25 -> y1 ,
. V_41 = F_19 ( V_25 ) ,
. V_42 = F_20 ( V_25 ) ,
. V_43 = V_26 -> V_39 ,
. V_44 = V_26 -> y1 ,
. V_45 = F_19 ( V_26 ) ,
. V_46 = F_20 ( V_26 ) ,
. V_27 = V_27 ,
. V_30 = * V_30 ,
} ;
int V_47 ;
V_47 = F_7 ( & V_16 , V_18 ,
V_19 , V_20 ,
V_21 ,
V_22 ) ;
if ( V_47 )
return V_47 ;
* V_25 = V_16 . V_25 ;
* V_26 = V_16 . V_26 ;
* V_30 = V_16 . V_30 ;
return 0 ;
}
int F_21 ( struct V_36 * V_37 , struct V_1 * V_2 ,
struct V_23 * V_24 ,
int V_43 , int V_44 ,
unsigned int V_45 , unsigned int V_46 ,
T_1 V_38 , T_1 V_40 ,
T_1 V_41 , T_1 V_42 )
{
struct V_48 V_49 = {
. V_2 = V_2 ,
. V_24 = V_24 ,
. V_50 = & V_2 -> V_50 ,
. V_51 = V_38 >> 16 ,
. V_52 = V_40 >> 16 ,
} ;
struct V_17 V_25 = {
. V_39 = V_38 ,
. y1 = V_40 ,
. V_53 = V_38 + V_41 ,
. V_54 = V_40 + V_42 ,
} ;
struct V_17 V_55 = {
. V_39 = V_43 ,
. y1 = V_44 ,
. V_53 = V_43 + V_45 ,
. V_54 = V_44 + V_46 ,
} ;
const struct V_17 V_18 = {
. V_53 = V_2 -> V_50 . V_56 ,
. V_54 = V_2 -> V_50 . V_57 ,
} ;
struct V_3 * * V_4 ;
int V_5 , V_47 ;
bool V_30 ;
V_47 = F_18 ( V_37 , V_2 , V_24 ,
& V_25 , & V_55 , & V_18 ,
V_58 ,
V_59 ,
V_59 ,
false , false , & V_30 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_30 )
return V_37 -> V_60 -> V_61 ( V_37 ) ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_22 ( V_5 == 0 ) ;
V_4 = F_23 ( V_5 * sizeof( * V_4 ) ,
V_62 ) ;
if ( ! V_4 )
return - V_63 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_49 . V_64 = V_4 ;
V_49 . V_5 = V_5 ;
V_47 = V_2 -> V_60 -> V_65 ( & V_49 ) ;
F_24 ( V_4 ) ;
return V_47 ;
}
int F_25 ( struct V_36 * V_37 )
{
return - V_32 ;
}
void F_26 ( struct V_36 * V_37 )
{
F_27 ( V_37 ) ;
F_24 ( V_37 ) ;
}
int F_28 ( struct V_36 * V_37 ,
struct V_15 * V_66 ,
struct V_23 * V_67 )
{
const struct V_68 * V_69 ;
struct V_1 * V_2 [ 2 ] ;
const struct V_70 * V_71 [ 2 ] ;
int V_72 , V_47 = 0 ;
V_69 = V_37 -> V_73 ;
V_2 [ 0 ] = V_37 -> V_2 ;
V_2 [ 1 ] = V_2 [ 0 ] != V_66 -> V_2 ? V_66 -> V_2 : NULL ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ )
V_71 [ V_72 ] = V_2 [ V_72 ] ? V_2 [ V_72 ] -> V_73 : NULL ;
if ( V_69 -> V_74 ) {
V_47 = V_69 -> V_74 ( V_37 , V_66 ) ;
if ( V_47 )
goto V_75;
}
if ( V_69 -> V_76 && V_66 -> V_24 &&
V_66 -> V_24 != V_67 ) {
V_47 = V_69 -> V_76 ( V_37 ,
V_66 ) ;
if ( V_47 )
goto V_75;
}
F_29 ( V_37 -> V_16 , V_66 ) ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
if ( V_71 [ V_72 ] && V_71 [ V_72 ] -> V_77 )
V_71 [ V_72 ] -> V_77 ( V_2 [ V_72 ] , V_2 [ V_72 ] -> V_16 ) ;
}
if ( F_30 ( V_37 , V_66 ) &&
V_69 -> V_78 )
V_69 -> V_78 ( V_37 , V_66 ) ;
else
V_69 -> V_79 ( V_37 , V_66 ) ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
if ( V_71 [ V_72 ] && V_71 [ V_72 ] -> V_80 )
V_71 [ V_72 ] -> V_80 ( V_2 [ V_72 ] , V_2 [ V_72 ] -> V_16 ) ;
}
if ( V_37 -> V_16 -> V_24 == V_67 )
goto V_75;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
if ( ! V_2 [ V_72 ] )
continue;
if ( V_2 [ V_72 ] -> V_81 == V_37 )
continue;
V_47 = F_31 ( V_2 [ V_72 ] ) ;
if ( V_47 == 0 ) {
F_32 ( V_2 [ V_72 ] ) ;
F_33 ( V_2 [ V_72 ] ) ;
}
V_47 = 0 ;
}
if ( V_69 -> V_82 )
V_69 -> V_82 ( V_37 , V_66 ) ;
V_75:
if ( V_66 ) {
if ( V_37 -> V_60 -> V_83 )
V_37 -> V_60 -> V_83 ( V_37 , V_66 ) ;
else
F_34 ( V_37 , V_66 ) ;
}
return V_47 ;
}
int F_35 ( struct V_36 * V_37 , struct V_1 * V_2 ,
struct V_23 * V_24 ,
int V_43 , int V_44 ,
unsigned int V_45 , unsigned int V_46 ,
T_1 V_38 , T_1 V_40 ,
T_1 V_41 , T_1 V_42 )
{
struct V_15 * V_66 ;
if ( V_37 -> V_60 -> V_84 )
V_66 = V_37 -> V_60 -> V_84 ( V_37 ) ;
else {
if ( ! V_37 -> V_16 )
F_36 ( V_37 ) ;
V_66 = F_37 ( V_37 ) ;
}
if ( ! V_66 )
return - V_63 ;
V_66 -> V_37 = V_37 ;
V_66 -> V_2 = V_2 ;
F_38 ( V_66 , V_24 ) ;
V_66 -> V_43 = V_43 ;
V_66 -> V_44 = V_44 ;
V_66 -> V_46 = V_46 ;
V_66 -> V_45 = V_45 ;
V_66 -> V_38 = V_38 ;
V_66 -> V_40 = V_40 ;
V_66 -> V_42 = V_42 ;
V_66 -> V_41 = V_41 ;
return F_28 ( V_37 , V_66 , V_37 -> V_24 ) ;
}
int F_39 ( struct V_36 * V_37 )
{
struct V_15 * V_66 ;
if ( ! V_37 -> V_2 )
return 0 ;
if ( V_37 -> V_60 -> V_84 )
V_66 = V_37 -> V_60 -> V_84 ( V_37 ) ;
else {
if ( ! V_37 -> V_16 )
F_36 ( V_37 ) ;
V_66 = F_37 ( V_37 ) ;
}
if ( ! V_66 )
return - V_63 ;
V_66 -> V_37 = V_37 ;
V_66 -> V_2 = NULL ;
F_38 ( V_66 , NULL ) ;
return F_28 ( V_37 , V_66 , V_37 -> V_24 ) ;
}
