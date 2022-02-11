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
const struct V_15 * V_16 ,
int V_17 ,
int V_18 ,
bool V_19 ,
bool V_20 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_21 * V_22 = V_14 -> V_22 ;
struct V_15 * V_23 = & V_14 -> V_23 ;
struct V_15 * V_24 = & V_14 -> V_24 ;
unsigned int V_25 = V_14 -> V_25 ;
int V_26 , V_27 ;
* V_23 = F_6 ( V_14 ) ;
* V_24 = F_7 ( V_14 ) ;
if ( ! V_22 ) {
V_14 -> V_28 = false ;
return 0 ;
}
if ( F_2 ( ! V_2 ) ) {
V_14 -> V_28 = false ;
return 0 ;
}
if ( ! V_2 -> V_29 && ! V_20 ) {
F_8 ( L_1 ) ;
return - V_30 ;
}
F_9 ( V_23 , V_22 -> V_31 << 16 , V_22 -> V_32 << 16 , V_25 ) ;
V_26 = F_10 ( V_23 , V_24 , V_17 , V_18 ) ;
V_27 = F_11 ( V_23 , V_24 , V_17 , V_18 ) ;
if ( V_26 < 0 || V_27 < 0 ) {
F_8 ( L_2 ) ;
F_12 ( L_3 , & V_14 -> V_23 , true ) ;
F_12 ( L_4 , & V_14 -> V_24 , false ) ;
return - V_33 ;
}
V_14 -> V_28 = F_13 ( V_23 , V_24 , V_16 , V_26 , V_27 ) ;
F_14 ( V_23 , V_22 -> V_31 << 16 , V_22 -> V_32 << 16 , V_25 ) ;
if ( ! V_14 -> V_28 )
return 0 ;
if ( ! V_19 && ! F_15 ( V_24 , V_16 ) ) {
F_8 ( L_5 ) ;
F_12 ( L_4 , V_24 , false ) ;
F_12 ( L_6 , V_16 , false ) ;
return - V_30 ;
}
return 0 ;
}
int F_16 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_15 * V_23 ,
struct V_15 * V_24 ,
const struct V_15 * V_16 ,
unsigned int V_25 ,
int V_17 ,
int V_18 ,
bool V_19 ,
bool V_20 ,
bool * V_28 )
{
struct V_13 V_14 = {
. V_35 = V_35 ,
. V_2 = V_2 ,
. V_22 = V_22 ,
. V_36 = V_23 -> V_37 ,
. V_38 = V_23 -> y1 ,
. V_39 = F_17 ( V_23 ) ,
. V_40 = F_18 ( V_23 ) ,
. V_41 = V_24 -> V_37 ,
. V_42 = V_24 -> y1 ,
. V_43 = F_17 ( V_24 ) ,
. V_44 = F_18 ( V_24 ) ,
. V_25 = V_25 ,
. V_28 = * V_28 ,
} ;
int V_45 ;
V_45 = F_5 ( & V_14 , V_16 ,
V_17 , V_18 ,
V_19 ,
V_20 ) ;
if ( V_45 )
return V_45 ;
* V_23 = V_14 . V_23 ;
* V_24 = V_14 . V_24 ;
* V_28 = V_14 . V_28 ;
return 0 ;
}
int F_19 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_21 * V_22 ,
int V_41 , int V_42 ,
unsigned int V_43 , unsigned int V_44 ,
T_1 V_36 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 )
{
struct V_46 V_47 = {
. V_2 = V_2 ,
. V_22 = V_22 ,
. V_48 = & V_2 -> V_48 ,
. V_49 = V_36 >> 16 ,
. V_50 = V_38 >> 16 ,
} ;
struct V_15 V_23 = {
. V_37 = V_36 ,
. y1 = V_38 ,
. V_51 = V_36 + V_39 ,
. V_52 = V_38 + V_40 ,
} ;
struct V_15 V_53 = {
. V_37 = V_41 ,
. y1 = V_42 ,
. V_51 = V_41 + V_43 ,
. V_52 = V_42 + V_44 ,
} ;
const struct V_15 V_16 = {
. V_51 = V_2 -> V_48 . V_54 ,
. V_52 = V_2 -> V_48 . V_55 ,
} ;
struct V_3 * * V_4 ;
int V_5 , V_45 ;
bool V_28 ;
V_45 = F_16 ( V_35 , V_2 , V_22 ,
& V_23 , & V_53 , & V_16 ,
V_56 ,
V_57 ,
V_57 ,
false , false , & V_28 ) ;
if ( V_45 )
return V_45 ;
if ( ! V_28 )
return V_35 -> V_58 -> V_59 ( V_35 ) ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_20 ( V_5 == 0 ) ;
V_4 = F_21 ( V_5 * sizeof( * V_4 ) ,
V_60 ) ;
if ( ! V_4 )
return - V_61 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_47 . V_62 = V_4 ;
V_47 . V_5 = V_5 ;
V_45 = V_2 -> V_58 -> V_63 ( & V_47 ) ;
F_22 ( V_4 ) ;
return V_45 ;
}
int F_23 ( struct V_34 * V_35 )
{
return - V_30 ;
}
void F_24 ( struct V_34 * V_35 )
{
F_25 ( V_35 ) ;
F_22 ( V_35 ) ;
}
int F_26 ( struct V_34 * V_35 ,
struct V_13 * V_64 ,
struct V_21 * V_65 )
{
const struct V_66 * V_67 ;
struct V_1 * V_2 [ 2 ] ;
const struct V_68 * V_69 [ 2 ] ;
int V_70 , V_45 = 0 ;
V_67 = V_35 -> V_71 ;
V_2 [ 0 ] = V_35 -> V_2 ;
V_2 [ 1 ] = V_2 [ 0 ] != V_64 -> V_2 ? V_64 -> V_2 : NULL ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ )
V_69 [ V_70 ] = V_2 [ V_70 ] ? V_2 [ V_70 ] -> V_71 : NULL ;
if ( V_67 -> V_72 ) {
V_45 = V_67 -> V_72 ( V_35 , V_64 ) ;
if ( V_45 )
goto V_73;
}
if ( V_67 -> V_74 && V_64 -> V_22 &&
V_64 -> V_22 != V_65 ) {
V_45 = V_67 -> V_74 ( V_35 ,
V_64 ) ;
if ( V_45 )
goto V_73;
}
F_27 ( V_35 -> V_14 , V_64 ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( V_69 [ V_70 ] && V_69 [ V_70 ] -> V_75 )
V_69 [ V_70 ] -> V_75 ( V_2 [ V_70 ] , V_2 [ V_70 ] -> V_14 ) ;
}
if ( F_28 ( V_35 , V_64 ) &&
V_67 -> V_76 )
V_67 -> V_76 ( V_35 , V_64 ) ;
else
V_67 -> V_77 ( V_35 , V_64 ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( V_69 [ V_70 ] && V_69 [ V_70 ] -> V_78 )
V_69 [ V_70 ] -> V_78 ( V_2 [ V_70 ] , V_2 [ V_70 ] -> V_14 ) ;
}
if ( V_35 -> V_14 -> V_22 == V_65 )
goto V_73;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( ! V_2 [ V_70 ] )
continue;
if ( V_2 [ V_70 ] -> V_79 == V_35 )
continue;
V_45 = F_29 ( V_2 [ V_70 ] ) ;
if ( V_45 == 0 ) {
F_30 ( V_2 [ V_70 ] ) ;
F_31 ( V_2 [ V_70 ] ) ;
}
V_45 = 0 ;
}
if ( V_67 -> V_80 )
V_67 -> V_80 ( V_35 , V_64 ) ;
V_73:
if ( V_64 ) {
if ( V_35 -> V_58 -> V_81 )
V_35 -> V_58 -> V_81 ( V_35 , V_64 ) ;
else
F_32 ( V_35 , V_64 ) ;
}
return V_45 ;
}
int F_33 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_21 * V_22 ,
int V_41 , int V_42 ,
unsigned int V_43 , unsigned int V_44 ,
T_1 V_36 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 )
{
struct V_13 * V_64 ;
if ( V_35 -> V_58 -> V_82 )
V_64 = V_35 -> V_58 -> V_82 ( V_35 ) ;
else {
if ( ! V_35 -> V_14 )
F_34 ( V_35 ) ;
V_64 = F_35 ( V_35 ) ;
}
if ( ! V_64 )
return - V_61 ;
V_64 -> V_35 = V_35 ;
V_64 -> V_2 = V_2 ;
F_36 ( V_64 , V_22 ) ;
V_64 -> V_41 = V_41 ;
V_64 -> V_42 = V_42 ;
V_64 -> V_44 = V_44 ;
V_64 -> V_43 = V_43 ;
V_64 -> V_36 = V_36 ;
V_64 -> V_38 = V_38 ;
V_64 -> V_40 = V_40 ;
V_64 -> V_39 = V_39 ;
return F_26 ( V_35 , V_64 , V_35 -> V_22 ) ;
}
int F_37 ( struct V_34 * V_35 )
{
struct V_13 * V_64 ;
if ( ! V_35 -> V_2 )
return 0 ;
if ( V_35 -> V_58 -> V_82 )
V_64 = V_35 -> V_58 -> V_82 ( V_35 ) ;
else {
if ( ! V_35 -> V_14 )
F_34 ( V_35 ) ;
V_64 = F_35 ( V_35 ) ;
}
if ( ! V_64 )
return - V_61 ;
V_64 -> V_35 = V_35 ;
V_64 -> V_2 = NULL ;
F_36 ( V_64 , NULL ) ;
return F_26 ( V_35 , V_64 , V_35 -> V_22 ) ;
}
