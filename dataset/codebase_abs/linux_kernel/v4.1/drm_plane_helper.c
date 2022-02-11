static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_8 ;
int V_9 = 0 ;
F_2 ( ! F_3 ( & V_7 -> V_10 . V_11 ) ) ;
F_4 (connector, &dev->mode_config.connector_list, head)
if ( V_8 -> V_12 && V_8 -> V_12 -> V_2 == V_2 ) {
if ( V_4 != NULL && V_9 < V_5 )
* ( V_4 ++ ) = V_8 ;
V_9 ++ ;
}
return V_9 ;
}
int F_5 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_17 * V_19 ,
const struct V_17 * V_20 ,
int V_21 ,
int V_22 ,
bool V_23 ,
bool V_24 ,
bool * V_25 )
{
int V_26 , V_27 ;
if ( ! V_16 ) {
* V_25 = false ;
return 0 ;
}
if ( F_2 ( ! V_2 ) ) {
* V_25 = false ;
return 0 ;
}
if ( ! V_2 -> V_28 && ! V_24 ) {
F_6 ( L_1 ) ;
return - V_29 ;
}
V_26 = F_7 ( V_18 , V_19 , V_21 , V_22 ) ;
V_27 = F_8 ( V_18 , V_19 , V_21 , V_22 ) ;
if ( V_26 < 0 || V_27 < 0 ) {
F_6 ( L_2 ) ;
return - V_30 ;
}
* V_25 = F_9 ( V_18 , V_19 , V_20 , V_26 , V_27 ) ;
if ( ! * V_25 )
return 0 ;
if ( ! V_23 && ! F_10 ( V_19 , V_20 ) ) {
F_6 ( L_3 ) ;
return - V_29 ;
}
return 0 ;
}
int F_11 ( struct V_13 * V_14 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_31 , int V_32 ,
unsigned int V_33 , unsigned int V_34 ,
T_1 V_35 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 )
{
struct V_39 V_40 = {
. V_2 = V_2 ,
. V_16 = V_16 ,
. V_41 = & V_2 -> V_41 ,
. V_42 = V_35 >> 16 ,
. V_43 = V_36 >> 16 ,
} ;
struct V_17 V_18 = {
. V_44 = V_35 ,
. y1 = V_36 ,
. V_45 = V_35 + V_37 ,
. V_46 = V_36 + V_38 ,
} ;
struct V_17 V_19 = {
. V_44 = V_31 ,
. y1 = V_32 ,
. V_45 = V_31 + V_33 ,
. V_46 = V_32 + V_34 ,
} ;
const struct V_17 V_20 = {
. V_45 = V_2 -> V_41 . V_47 ,
. V_46 = V_2 -> V_41 . V_48 ,
} ;
struct V_3 * * V_4 ;
int V_5 , V_49 ;
bool V_25 ;
V_49 = F_5 ( V_14 , V_2 , V_16 ,
& V_18 , & V_19 , & V_20 ,
V_50 ,
V_50 ,
false , false , & V_25 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_25 )
return V_14 -> V_51 -> V_52 ( V_14 ) ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_12 ( V_5 == 0 ) ;
V_4 = F_13 ( V_5 * sizeof( * V_4 ) ,
V_53 ) ;
if ( ! V_4 )
return - V_54 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_40 . V_55 = V_4 ;
V_40 . V_5 = V_5 ;
V_49 = V_2 -> V_51 -> V_56 ( & V_40 ) ;
F_14 ( V_4 ) ;
return V_49 ;
}
int F_15 ( struct V_13 * V_14 )
{
return - V_29 ;
}
void F_16 ( struct V_13 * V_14 )
{
F_17 ( V_14 ) ;
F_14 ( V_14 ) ;
}
static struct V_13 * F_18 ( struct V_6 * V_7 )
{
struct V_13 * V_57 ;
int V_49 ;
V_57 = F_13 ( sizeof( * V_57 ) , V_53 ) ;
if ( V_57 == NULL ) {
F_6 ( L_4 ) ;
return NULL ;
}
V_57 -> V_58 = true ;
V_49 = F_19 ( V_7 , V_57 , 0 ,
& V_59 ,
V_60 ,
F_20 ( V_60 ) ,
V_61 ) ;
if ( V_49 ) {
F_14 ( V_57 ) ;
V_57 = NULL ;
}
return V_57 ;
}
int F_21 ( struct V_6 * V_7 , struct V_1 * V_2 ,
const struct V_62 * V_51 )
{
struct V_13 * V_57 ;
V_57 = F_18 ( V_7 ) ;
return F_22 ( V_7 , V_2 , V_57 , NULL , V_51 ) ;
}
int F_23 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
struct V_15 * V_65 )
{
const struct V_66 * V_67 ;
struct V_1 * V_2 [ 2 ] ;
const struct V_68 * V_69 [ 2 ] ;
int V_70 , V_49 = 0 ;
V_67 = V_14 -> V_71 ;
V_2 [ 0 ] = V_14 -> V_2 ;
V_2 [ 1 ] = V_2 [ 0 ] != V_64 -> V_2 ? V_64 -> V_2 : NULL ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ )
V_69 [ V_70 ] = V_2 [ V_70 ] ? V_2 [ V_70 ] -> V_71 : NULL ;
if ( V_67 -> V_72 ) {
V_49 = V_67 -> V_72 ( V_14 , V_64 ) ;
if ( V_49 )
goto V_73;
}
if ( V_67 -> V_74 && V_64 -> V_16 &&
V_64 -> V_16 != V_65 ) {
V_49 = V_67 -> V_74 ( V_14 , V_64 -> V_16 ,
V_64 ) ;
if ( V_49 )
goto V_73;
}
F_24 ( V_14 -> V_75 , V_64 ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( V_69 [ V_70 ] && V_69 [ V_70 ] -> V_76 )
V_69 [ V_70 ] -> V_76 ( V_2 [ V_70 ] ) ;
}
if ( F_25 ( V_14 , V_64 ) &&
V_67 -> V_77 )
V_67 -> V_77 ( V_14 , V_64 ) ;
else
V_67 -> V_78 ( V_14 , V_64 ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( V_69 [ V_70 ] && V_69 [ V_70 ] -> V_79 )
V_69 [ V_70 ] -> V_79 ( V_2 [ V_70 ] ) ;
}
if ( V_14 -> V_75 -> V_16 == V_65 )
goto V_73;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
if ( ! V_2 [ V_70 ] )
continue;
if ( V_2 [ V_70 ] -> V_80 == V_14 )
continue;
V_49 = F_26 ( V_2 [ V_70 ] ) ;
if ( V_49 == 0 ) {
F_27 ( V_2 [ V_70 ] ) ;
F_28 ( V_2 [ V_70 ] ) ;
}
V_49 = 0 ;
}
if ( V_67 -> V_81 && V_65 )
V_67 -> V_81 ( V_14 , V_65 , V_64 ) ;
V_73:
if ( V_64 ) {
if ( V_14 -> V_51 -> V_82 )
V_14 -> V_51 -> V_82 ( V_14 , V_64 ) ;
else
F_29 ( V_14 , V_64 ) ;
}
return V_49 ;
}
int F_30 ( struct V_13 * V_14 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_31 , int V_32 ,
unsigned int V_33 , unsigned int V_34 ,
T_1 V_35 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 )
{
struct V_63 * V_64 ;
if ( V_14 -> V_51 -> V_83 )
V_64 = V_14 -> V_51 -> V_83 ( V_14 ) ;
else if ( V_14 -> V_75 )
V_64 = F_31 ( V_14 ) ;
else
V_64 = F_13 ( sizeof( * V_64 ) , V_53 ) ;
if ( ! V_64 )
return - V_54 ;
V_64 -> V_14 = V_14 ;
V_64 -> V_2 = V_2 ;
F_32 ( V_64 , V_16 ) ;
V_64 -> V_31 = V_31 ;
V_64 -> V_32 = V_32 ;
V_64 -> V_34 = V_34 ;
V_64 -> V_33 = V_33 ;
V_64 -> V_35 = V_35 ;
V_64 -> V_36 = V_36 ;
V_64 -> V_38 = V_38 ;
V_64 -> V_37 = V_37 ;
return F_23 ( V_14 , V_64 , V_14 -> V_16 ) ;
}
int F_33 ( struct V_13 * V_14 )
{
struct V_63 * V_64 ;
if ( ! V_14 -> V_2 )
return 0 ;
if ( V_14 -> V_51 -> V_83 )
V_64 = V_14 -> V_51 -> V_83 ( V_14 ) ;
else if ( V_14 -> V_75 )
V_64 = F_31 ( V_14 ) ;
else
V_64 = F_13 ( sizeof( * V_64 ) , V_53 ) ;
if ( ! V_64 )
return - V_54 ;
V_64 -> V_14 = V_14 ;
V_64 -> V_2 = NULL ;
F_32 ( V_64 , NULL ) ;
return F_23 ( V_14 , V_64 , V_14 -> V_16 ) ;
}
