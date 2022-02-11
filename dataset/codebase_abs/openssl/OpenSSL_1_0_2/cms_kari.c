int F_1 ( T_1 * V_1 ,
T_2 * * V_2 ,
T_3 * * V_3 )
{
if ( V_1 -> type != V_4 ) {
F_2 ( V_5 ,
V_6 ) ;
return 0 ;
}
if ( V_2 )
* V_2 = V_1 -> V_7 . V_8 -> V_9 ;
if ( V_3 )
* V_3 = V_1 -> V_7 . V_8 -> V_10 ;
return 1 ;
}
int F_3 ( T_1 * V_1 , T_4 * V_11 )
{
T_5 * V_12 ;
if ( V_1 -> type != V_4 ) {
F_2 ( V_13 ,
V_6 ) ;
return - 2 ;
}
V_12 = V_1 -> V_7 . V_8 -> V_14 ;
if ( V_12 -> type == V_15 )
return F_4 ( V_12 -> V_7 . V_16 , V_11 ) ;
else if ( V_12 -> type == V_17 )
return F_5 ( V_12 -> V_7 . V_18 , V_11 ) ;
return - 1 ;
}
int F_6 ( T_6 * V_19 ,
T_3 * * V_20 ,
T_7 * * V_21 ,
T_8 * * V_22 ,
T_9 * * V_23 , T_10 * * V_24 )
{
T_11 * V_25 = V_19 -> V_25 ;
if ( V_25 -> type == V_26 ) {
if ( V_23 )
* V_23 = V_25 -> V_7 . V_16 -> V_23 ;
if ( V_24 )
* V_24 = V_25 -> V_7 . V_16 -> V_27 ;
if ( V_20 )
* V_20 = NULL ;
if ( V_21 )
* V_21 = NULL ;
if ( V_22 )
* V_22 = NULL ;
} else if ( V_25 -> type == V_28 ) {
if ( V_20 )
* V_20 = V_25 -> V_7 . V_29 -> V_18 ;
if ( V_21 )
* V_21 = V_25 -> V_7 . V_29 -> V_30 ;
if ( V_22 )
* V_22 = V_25 -> V_7 . V_29 -> V_22 ;
if ( V_23 )
* V_23 = NULL ;
if ( V_24 )
* V_24 = NULL ;
} else
return 0 ;
return 1 ;
}
int F_7 ( T_6 * V_19 ,
T_4 * V_11 )
{
T_11 * V_25 = V_19 -> V_25 ;
if ( V_25 -> type == V_26 )
return F_4 ( V_25 -> V_7 . V_16 , V_11 ) ;
else if ( V_25 -> type == V_28 )
return F_5 ( V_25 -> V_7 . V_29 -> V_18 , V_11 ) ;
else
return - 1 ;
}
int F_8 ( T_1 * V_1 , T_12 * V_31 )
{
T_13 * V_32 ;
T_14 * V_8 = V_1 -> V_7 . V_8 ;
if ( V_8 -> V_32 ) {
F_9 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
}
if ( ! V_31 )
return 1 ;
V_32 = F_10 ( V_31 , NULL ) ;
if ( ! V_32 || ! F_11 ( V_32 ) )
goto V_33;
V_8 -> V_32 = V_32 ;
return 1 ;
V_33:
if ( V_32 )
F_9 ( V_32 ) ;
return 0 ;
}
T_15 * F_12 ( T_1 * V_1 )
{
if ( V_1 -> type == V_4 )
return & V_1 -> V_7 . V_8 -> V_34 ;
return NULL ;
}
static int F_13 ( unsigned char * * V_35 , T_16 * V_36 ,
const unsigned char * V_37 , T_16 V_38 ,
T_14 * V_8 , int V_39 )
{
unsigned char V_40 [ V_41 ] ;
T_16 V_42 ;
int V_43 = 0 ;
unsigned char * V_44 = NULL ;
int V_45 ;
V_42 = F_14 ( & V_8 -> V_34 ) ;
if ( V_42 > V_41 )
return 0 ;
if ( F_15 ( V_8 -> V_32 , V_40 , & V_42 ) <= 0 )
goto V_33;
if ( ! F_16 ( & V_8 -> V_34 , NULL , NULL , V_40 , NULL , V_39 ) )
goto V_33;
if ( ! F_17 ( & V_8 -> V_34 , NULL , & V_45 , V_37 , V_38 ) )
goto V_33;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_33;
if ( ! F_17 ( & V_8 -> V_34 , V_44 , & V_45 , V_37 , V_38 ) )
goto V_33;
* V_35 = V_44 ;
* V_36 = ( T_16 ) V_45 ;
V_43 = 1 ;
V_33:
F_19 ( V_40 , V_42 ) ;
if ( ! V_43 && V_44 )
F_20 ( V_44 ) ;
F_21 ( & V_8 -> V_34 ) ;
F_9 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
return V_43 ;
}
int F_22 ( T_17 * V_46 ,
T_1 * V_1 ,
T_6 * V_19 )
{
int V_43 = 0 ;
unsigned char * V_47 = NULL , * V_48 = NULL ;
T_16 V_49 ;
T_16 V_50 ;
T_18 * V_51 ;
V_49 = V_19 -> V_52 -> V_53 ;
V_47 = V_19 -> V_52 -> V_54 ;
if ( ! F_23 ( V_1 , 1 ) )
goto V_33;
if ( ! F_13 ( & V_48 , & V_50 , V_47 , V_49 , V_1 -> V_7 . V_8 , 0 ) )
goto V_33;
V_51 = V_46 -> V_7 . V_55 -> V_56 ;
if ( V_51 -> V_57 ) {
F_19 ( V_51 -> V_57 , V_51 -> V_58 ) ;
F_20 ( V_51 -> V_57 ) ;
}
V_51 -> V_57 = V_48 ;
V_51 -> V_58 = V_50 ;
V_48 = NULL ;
V_43 = 1 ;
V_33:
if ( V_48 )
F_20 ( V_48 ) ;
return V_43 ;
}
static int F_24 ( T_14 * V_8 ,
T_12 * V_31 )
{
T_13 * V_32 = NULL ;
T_12 * V_59 = NULL ;
int V_43 = 0 ;
V_32 = F_10 ( V_31 , NULL ) ;
if ( ! V_32 )
goto V_33;
if ( F_25 ( V_32 ) <= 0 )
goto V_33;
if ( F_26 ( V_32 , & V_59 ) <= 0 )
goto V_33;
F_9 ( V_32 ) ;
V_32 = F_10 ( V_59 , NULL ) ;
if ( ! V_32 )
goto V_33;
if ( F_11 ( V_32 ) <= 0 )
goto V_33;
V_8 -> V_32 = V_32 ;
V_43 = 1 ;
V_33:
if ( ! V_43 && V_32 )
F_9 ( V_32 ) ;
if ( V_59 )
F_27 ( V_59 ) ;
return V_43 ;
}
int F_28 ( T_1 * V_1 , T_4 * V_60 ,
T_12 * V_31 , unsigned int V_61 )
{
T_14 * V_8 ;
T_6 * V_19 = NULL ;
V_1 -> V_7 . V_8 = F_29 ( T_14 ) ;
if ( ! V_1 -> V_7 . V_8 )
return 0 ;
V_1 -> type = V_4 ;
V_8 = V_1 -> V_7 . V_8 ;
V_8 -> V_62 = 3 ;
V_19 = F_29 ( T_6 ) ;
if ( ! F_30 ( V_8 -> V_63 , V_19 ) ) {
F_31 ( V_19 , T_6 ) ;
return 0 ;
}
if ( V_61 & V_64 ) {
V_19 -> V_25 -> type = V_28 ;
if ( ! F_32 ( & V_19 -> V_25 -> V_7 . V_29 -> V_18 , V_60 ) )
return 0 ;
} else {
V_19 -> V_25 -> type = V_26 ;
if ( ! F_33 ( & V_19 -> V_25 -> V_7 . V_16 , V_60 ) )
return 0 ;
}
if ( ! F_24 ( V_8 , V_31 ) )
return 0 ;
F_34 ( & V_31 -> V_65 , 1 , V_66 ) ;
V_19 -> V_67 = V_31 ;
return 1 ;
}
static int F_35 ( T_14 * V_8 ,
const T_19 * V_68 )
{
T_15 * V_34 = & V_8 -> V_34 ;
const T_19 * V_69 ;
int V_58 = F_36 ( V_68 ) ;
V_69 = F_37 ( V_34 ) ;
if ( V_69 ) {
if ( F_38 ( V_34 ) != V_70 )
return 0 ;
return 1 ;
}
if ( F_39 ( V_68 ) == V_71 )
V_69 = F_40 () ;
else if ( V_58 <= 16 )
V_69 = F_41 () ;
else if ( V_58 <= 24 )
V_69 = F_42 () ;
else
V_69 = F_43 () ;
return F_44 ( V_34 , V_69 , NULL , NULL , NULL ) ;
}
int F_45 ( T_17 * V_46 ,
T_1 * V_1 )
{
T_14 * V_8 ;
T_18 * V_51 ;
T_6 * V_19 ;
F_46 ( T_6 ) * V_72 ;
int V_73 ;
if ( V_1 -> type != V_4 ) {
F_2 ( V_74 , V_6 ) ;
return 0 ;
}
V_8 = V_1 -> V_7 . V_8 ;
V_72 = V_8 -> V_63 ;
V_51 = V_46 -> V_7 . V_55 -> V_56 ;
if ( ! F_35 ( V_8 , V_51 -> V_68 ) )
return 0 ;
if ( V_8 -> V_14 -> type == - 1 ) {
T_5 * V_12 = V_8 -> V_14 ;
V_12 -> type = V_75 ;
V_12 -> V_7 . V_76 = F_29 ( V_77 ) ;
if ( ! V_12 -> V_7 . V_76 )
return 0 ;
}
if ( ! F_23 ( V_1 , 0 ) )
return 0 ;
for ( V_73 = 0 ; V_73 < F_47 ( V_72 ) ; V_73 ++ ) {
unsigned char * V_47 ;
T_16 V_49 ;
V_19 = F_48 ( V_72 , V_73 ) ;
if ( F_49 ( V_8 -> V_32 , V_19 -> V_67 ) <= 0 )
return 0 ;
if ( ! F_13 ( & V_47 , & V_49 , V_51 -> V_57 , V_51 -> V_58 ,
V_8 , 1 ) )
return 0 ;
F_50 ( V_19 -> V_52 , V_47 , V_49 ) ;
}
return 1 ;
}
