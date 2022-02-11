T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 )
{
T_1 * V_3 = NULL ;
if ( ( V_3 = F_2 () ) == NULL )
return NULL ;
F_3 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_2 ;
if ( V_1 && ! F_4 ( V_1 -> V_5 . V_6 , V_3 ) ) {
V_3 -> V_4 = NULL ;
goto V_7;
}
return V_3 ;
V_7:
F_5 ( V_3 ) ;
return NULL ;
}
int F_6 ( T_2 * V_1 , T_4 * V_8 )
{
T_5 * V_9 ;
V_9 = F_7 () ;
if ( V_9 == NULL )
return 0 ;
if ( ! F_8 ( & V_9 -> V_10 . V_11 , V_8 ) ) {
F_9 ( V_9 ) ;
return 0 ;
}
V_9 -> type = V_12 ;
F_9 ( V_1 -> V_5 . V_13 ) ;
V_1 -> V_5 . V_13 = V_9 ;
return 1 ;
}
int F_10 ( T_2 * V_1 , T_6 * V_14 )
{
T_7 * V_15 ;
if ( V_1 -> V_16 == NULL )
V_1 -> V_16 = F_11 () ;
V_15 = V_1 -> V_16 ;
if ( V_15 == NULL )
return 0 ;
if ( V_14 == NULL )
return 1 ;
if ( V_15 -> V_17 == NULL
&& ( V_15 -> V_17 = F_12 () ) == NULL )
return 0 ;
if ( ! F_13 ( V_15 -> V_17 , V_14 ) )
return 0 ;
F_14 ( V_14 ) ;
return 1 ;
}
int F_15 ( T_8 * V_18 )
{
return F_16 ( V_18 -> V_19 ) ;
}
T_9 * F_17 ( T_8 * V_18 )
{
T_10 * V_20 ;
V_20 = V_18 -> V_21 ;
if ( ! V_20 ) {
F_18 ( V_22 , V_23 ) ;
return NULL ;
}
if ( F_19 ( V_20 -> V_24 ) != V_25 ) {
F_18 ( V_22 , V_26 ) ;
return NULL ;
}
return F_20 ( V_20 -> V_27 , F_21 ( T_9 ) ) ;
}
const T_11 * F_22 ( const T_9 * V_28 )
{
return V_28 -> V_29 ;
}
int F_23 ( T_9 * V_28 )
{
if ( ! V_28 )
return - 1 ;
return F_24 ( V_28 -> V_30 . V_31 ) ;
}
T_12 * F_25 ( T_9 * V_28 , int V_32 )
{
if ( ! V_28 )
return NULL ;
return F_26 ( V_28 -> V_30 . V_31 , V_32 ) ;
}
const T_13 * F_27 ( const T_9 * V_28 )
{
return V_28 -> V_30 . V_33 ;
}
int F_28 ( const T_9 * V_28 ,
const T_11 * * V_34 ,
const T_4 * * V_35 )
{
const T_14 * V_36 = & V_28 -> V_30 . V_37 ;
if ( V_36 -> type == V_38 ) {
* V_35 = V_36 -> V_39 . V_40 ;
* V_34 = NULL ;
} else if ( V_36 -> type == V_41 ) {
* V_34 = V_36 -> V_39 . V_42 ;
* V_35 = NULL ;
} else {
return 0 ;
}
return 1 ;
}
int F_29 ( T_9 * V_28 , T_3 * V_43 , int V_44 )
{
int V_45 ;
F_30 ( T_12 ) * V_46 ;
T_12 * V_47 ;
if ( ! V_28 )
return - 1 ;
if ( V_44 < 0 )
V_44 = 0 ;
else
V_44 ++ ;
V_46 = V_28 -> V_30 . V_31 ;
for ( V_45 = V_44 ; V_45 < F_24 ( V_46 ) ; V_45 ++ ) {
V_47 = F_26 ( V_46 , V_45 ) ;
if ( ! F_31 ( V_43 , V_47 -> V_48 ) )
return V_45 ;
}
return - 1 ;
}
int F_32 ( T_12 * V_47 , int * V_49 ,
T_13 * * V_50 ,
T_13 * * V_51 ,
T_13 * * V_52 )
{
int V_53 ;
T_15 * V_54 ;
if ( ! V_47 )
return - 1 ;
V_54 = V_47 -> V_55 ;
V_53 = V_54 -> type ;
if ( V_53 == V_56 ) {
T_16 * V_57 = V_54 -> V_39 . V_58 ;
if ( V_50 )
* V_50 = V_57 -> V_59 ;
if ( V_49 ) {
if ( V_57 -> V_60 )
* V_49 = F_16 ( V_57 -> V_60 ) ;
else
* V_49 = - 1 ;
}
}
if ( V_51 )
* V_51 = V_47 -> V_61 ;
if ( V_52 )
* V_52 = V_47 -> V_62 ;
return V_53 ;
}
int F_33 ( T_9 * V_28 , T_3 * V_43 , int * V_63 ,
int * V_49 ,
T_13 * * V_50 ,
T_13 * * V_51 ,
T_13 * * V_52 )
{
int V_45 ;
T_12 * V_47 ;
V_45 = F_29 ( V_28 , V_43 , - 1 ) ;
if ( V_45 < 0 )
return 0 ;
V_47 = F_25 ( V_28 , V_45 ) ;
V_45 = F_32 ( V_47 , V_49 , V_50 , V_51 , V_52 ) ;
if ( V_63 )
* V_63 = V_45 ;
return 1 ;
}
int F_34 ( T_13 * V_51 ,
T_13 * V_52 , long V_64 , long V_65 )
{
int V_53 = 1 ;
T_17 V_66 , V_67 ;
time ( & V_66 ) ;
if ( ! F_35 ( V_51 ) ) {
F_18 ( V_68 , V_69 ) ;
V_53 = 0 ;
} else {
V_67 = V_66 + V_64 ;
if ( F_36 ( V_51 , & V_67 ) > 0 ) {
F_18 ( V_68 , V_70 ) ;
V_53 = 0 ;
}
if ( V_65 >= 0 ) {
V_67 = V_66 - V_65 ;
if ( F_36 ( V_51 , & V_67 ) < 0 ) {
F_18 ( V_68 , V_71 ) ;
V_53 = 0 ;
}
}
}
if ( ! V_52 )
return V_53 ;
if ( ! F_35 ( V_52 ) ) {
F_18 ( V_68 , V_72 ) ;
V_53 = 0 ;
} else {
V_67 = V_66 - V_64 ;
if ( F_36 ( V_52 , & V_67 ) < 0 ) {
F_18 ( V_68 , V_73 ) ;
V_53 = 0 ;
}
}
if ( F_37 ( V_52 , V_51 ) < 0 ) {
F_18 ( V_68 ,
V_74 ) ;
V_53 = 0 ;
}
return V_53 ;
}
const T_3 * F_38 ( const T_12 * V_47 )
{
return V_47 -> V_48 ;
}
