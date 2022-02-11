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
V_23 -> V_28 = V_14 -> V_29 ;
V_23 -> y1 = V_14 -> V_30 ;
V_23 -> V_31 = V_14 -> V_29 + V_14 -> V_32 ;
V_23 -> V_33 = V_14 -> V_30 + V_14 -> V_34 ;
V_24 -> V_28 = V_14 -> V_35 ;
V_24 -> y1 = V_14 -> V_36 ;
V_24 -> V_31 = V_14 -> V_35 + V_14 -> V_37 ;
V_24 -> V_33 = V_14 -> V_36 + V_14 -> V_38 ;
if ( ! V_22 ) {
V_14 -> V_39 = false ;
return 0 ;
}
if ( F_2 ( ! V_2 ) ) {
V_14 -> V_39 = false ;
return 0 ;
}
if ( ! V_2 -> V_40 && ! V_20 ) {
F_6 ( L_1 ) ;
return - V_41 ;
}
F_7 ( V_23 , V_22 -> V_42 << 16 , V_22 -> V_43 << 16 , V_25 ) ;
V_26 = F_8 ( V_23 , V_24 , V_17 , V_18 ) ;
V_27 = F_9 ( V_23 , V_24 , V_17 , V_18 ) ;
if ( V_26 < 0 || V_27 < 0 ) {
F_6 ( L_2 ) ;
F_10 ( L_3 , & V_14 -> V_23 , true ) ;
F_10 ( L_4 , & V_14 -> V_24 , false ) ;
return - V_44 ;
}
V_14 -> V_39 = F_11 ( V_23 , V_24 , V_16 , V_26 , V_27 ) ;
F_12 ( V_23 , V_22 -> V_42 << 16 , V_22 -> V_43 << 16 , V_25 ) ;
if ( ! V_14 -> V_39 )
return 0 ;
if ( ! V_19 && ! F_13 ( V_24 , V_16 ) ) {
F_6 ( L_5 ) ;
F_10 ( L_4 , V_24 , false ) ;
F_10 ( L_6 , V_16 , false ) ;
return - V_41 ;
}
return 0 ;
}
int F_14 ( struct V_45 * V_46 ,
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
bool * V_39 )
{
struct V_13 V_14 = {
. V_46 = V_46 ,
. V_2 = V_2 ,
. V_22 = V_22 ,
. V_29 = V_23 -> V_28 ,
. V_30 = V_23 -> y1 ,
. V_32 = F_15 ( V_23 ) ,
. V_34 = F_16 ( V_23 ) ,
. V_35 = V_24 -> V_28 ,
. V_36 = V_24 -> y1 ,
. V_37 = F_15 ( V_24 ) ,
. V_38 = F_16 ( V_24 ) ,
. V_25 = V_25 ,
. V_39 = * V_39 ,
} ;
int V_47 ;
V_47 = F_5 ( & V_14 , V_16 ,
V_17 , V_18 ,
V_19 ,
V_20 ) ;
if ( V_47 )
return V_47 ;
* V_23 = V_14 . V_23 ;
* V_24 = V_14 . V_24 ;
* V_39 = V_14 . V_39 ;
return 0 ;
}
int F_17 ( struct V_45 * V_46 , struct V_1 * V_2 ,
struct V_21 * V_22 ,
int V_35 , int V_36 ,
unsigned int V_37 , unsigned int V_38 ,
T_1 V_29 , T_1 V_30 ,
T_1 V_32 , T_1 V_34 )
{
struct V_48 V_49 = {
. V_2 = V_2 ,
. V_22 = V_22 ,
. V_50 = & V_2 -> V_50 ,
. V_51 = V_29 >> 16 ,
. V_52 = V_30 >> 16 ,
} ;
struct V_15 V_23 = {
. V_28 = V_29 ,
. y1 = V_30 ,
. V_31 = V_29 + V_32 ,
. V_33 = V_30 + V_34 ,
} ;
struct V_15 V_53 = {
. V_28 = V_35 ,
. y1 = V_36 ,
. V_31 = V_35 + V_37 ,
. V_33 = V_36 + V_38 ,
} ;
const struct V_15 V_16 = {
. V_31 = V_2 -> V_50 . V_54 ,
. V_33 = V_2 -> V_50 . V_55 ,
} ;
struct V_3 * * V_4 ;
int V_5 , V_47 ;
bool V_39 ;
V_47 = F_14 ( V_46 , V_2 , V_22 ,
& V_23 , & V_53 , & V_16 ,
V_56 ,
V_57 ,
V_57 ,
false , false , & V_39 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_39 )
return V_46 -> V_58 -> V_59 ( V_46 ) ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_18 ( V_5 == 0 ) ;
V_4 = F_19 ( V_5 * sizeof( * V_4 ) ,
V_60 ) ;
if ( ! V_4 )
return - V_61 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_49 . V_62 = V_4 ;
V_49 . V_5 = V_5 ;
V_47 = V_2 -> V_58 -> V_63 ( & V_49 ) ;
F_20 ( V_4 ) ;
return V_47 ;
}
int F_21 ( struct V_45 * V_46 )
{
return - V_41 ;
}
void F_22 ( struct V_45 * V_46 )
{
F_23 ( V_46 ) ;
F_20 ( V_46 ) ;
}
int F_24 ( struct V_45 * V_46 ,
struct V_13 * V_64 ,
struct V_21 * V_65 )
{
const struct V_66 * V_67 ;
struct V_1 * V_2 [ 2 ] ;
const struct V_68 * V_69 [ 2 ] ;
int V_70 , V_47 = 0 ;
V_67 = V_46 -> V_71 ;
V_2 [ 0 ] = V_46 -> V_2 ;
V_2 [ 1 ] = V_2 [ 0 ] != V_64 -> V_2 ? V_64 -> V_2 : NULL ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ )
V_69 [ V_70 ] = V_2 [ V_70 ] ? V_2 [ V_70 ] -> V_71 : NULL ;
if ( V_67 -> V_72 ) {
V_47 = V_67 -> V_72 ( V_46 , V_64 ) ;
if ( V_47 )
goto V_73;
}
if ( V_67 -> V_74 && V_64 -> V_22 &&
V_64 -> V_22 != V_65 ) {
V_47 = V_67 -> V_74 ( V_46 ,
V_64 ) ;
if ( V_47 )
goto V_73;
}
F_25 ( V_46 -> V_14 , V_64 ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( V_69 [ V_70 ] && V_69 [ V_70 ] -> V_75 )
V_69 [ V_70 ] -> V_75 ( V_2 [ V_70 ] , V_2 [ V_70 ] -> V_14 ) ;
}
if ( F_26 ( V_46 , V_64 ) &&
V_67 -> V_76 )
V_67 -> V_76 ( V_46 , V_64 ) ;
else
V_67 -> V_77 ( V_46 , V_64 ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( V_69 [ V_70 ] && V_69 [ V_70 ] -> V_78 )
V_69 [ V_70 ] -> V_78 ( V_2 [ V_70 ] , V_2 [ V_70 ] -> V_14 ) ;
}
if ( V_46 -> V_14 -> V_22 == V_65 )
goto V_73;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( ! V_2 [ V_70 ] )
continue;
if ( V_2 [ V_70 ] -> V_79 == V_46 )
continue;
V_47 = F_27 ( V_2 [ V_70 ] ) ;
if ( V_47 == 0 ) {
F_28 ( V_2 [ V_70 ] ) ;
F_29 ( V_2 [ V_70 ] ) ;
}
V_47 = 0 ;
}
if ( V_67 -> V_80 )
V_67 -> V_80 ( V_46 , V_64 ) ;
V_73:
if ( V_64 ) {
if ( V_46 -> V_58 -> V_81 )
V_46 -> V_58 -> V_81 ( V_46 , V_64 ) ;
else
F_30 ( V_46 , V_64 ) ;
}
return V_47 ;
}
int F_31 ( struct V_45 * V_46 , struct V_1 * V_2 ,
struct V_21 * V_22 ,
int V_35 , int V_36 ,
unsigned int V_37 , unsigned int V_38 ,
T_1 V_29 , T_1 V_30 ,
T_1 V_32 , T_1 V_34 )
{
struct V_13 * V_64 ;
if ( V_46 -> V_58 -> V_82 )
V_64 = V_46 -> V_58 -> V_82 ( V_46 ) ;
else {
if ( ! V_46 -> V_14 )
F_32 ( V_46 ) ;
V_64 = F_33 ( V_46 ) ;
}
if ( ! V_64 )
return - V_61 ;
V_64 -> V_46 = V_46 ;
V_64 -> V_2 = V_2 ;
F_34 ( V_64 , V_22 ) ;
V_64 -> V_35 = V_35 ;
V_64 -> V_36 = V_36 ;
V_64 -> V_38 = V_38 ;
V_64 -> V_37 = V_37 ;
V_64 -> V_29 = V_29 ;
V_64 -> V_30 = V_30 ;
V_64 -> V_34 = V_34 ;
V_64 -> V_32 = V_32 ;
return F_24 ( V_46 , V_64 , V_46 -> V_22 ) ;
}
int F_35 ( struct V_45 * V_46 )
{
struct V_13 * V_64 ;
if ( ! V_46 -> V_2 )
return 0 ;
if ( V_46 -> V_58 -> V_82 )
V_64 = V_46 -> V_58 -> V_82 ( V_46 ) ;
else {
if ( ! V_46 -> V_14 )
F_32 ( V_46 ) ;
V_64 = F_33 ( V_46 ) ;
}
if ( ! V_64 )
return - V_61 ;
V_64 -> V_46 = V_46 ;
V_64 -> V_2 = NULL ;
F_34 ( V_64 , NULL ) ;
return F_24 ( V_46 , V_64 , V_46 -> V_22 ) ;
}
