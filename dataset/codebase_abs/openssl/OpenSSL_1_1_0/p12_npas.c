int F_1 ( T_1 * V_1 , const char * V_2 , const char * V_3 )
{
if ( ! V_1 ) {
F_2 ( V_4 ,
V_5 ) ;
return 0 ;
}
if ( ! F_3 ( V_1 , V_2 , - 1 ) ) {
F_2 ( V_4 , V_6 ) ;
return 0 ;
}
if ( ! F_4 ( V_1 , V_2 , V_3 ) ) {
F_2 ( V_4 , V_7 ) ;
return 0 ;
}
return 1 ;
}
static int F_4 ( T_1 * V_1 , const char * V_2 , const char * V_3 )
{
F_5 ( V_8 ) * V_9 = NULL , * V_10 = NULL ;
F_5 ( V_11 ) * V_12 = NULL ;
int V_13 , V_14 , V_15 = 0 , V_16 = 0 , V_17 = 0 ;
V_8 * V_18 , * V_19 ;
T_2 * V_20 = NULL , * V_21 = NULL ;
unsigned char V_22 [ V_23 ] ;
unsigned int V_24 ;
int V_25 = 0 ;
if ( ( V_9 = F_6 ( V_1 ) ) == NULL )
goto V_26;
if ( ( V_10 = F_7 () ) == NULL )
goto V_26;
for ( V_13 = 0 ; V_13 < F_8 ( V_9 ) ; V_13 ++ ) {
V_18 = F_9 ( V_9 , V_13 ) ;
V_14 = F_10 ( V_18 -> type ) ;
if ( V_14 == V_27 ) {
V_12 = F_11 ( V_18 ) ;
} else if ( V_14 == V_28 ) {
V_12 = F_12 ( V_18 , V_2 , - 1 ) ;
if ( ! F_13 ( V_18 -> V_29 . V_30 -> V_31 -> V_32 ,
& V_15 , & V_16 , & V_17 ) )
goto V_26;
} else {
continue;
}
if ( V_12 == NULL )
goto V_26;
if ( ! F_14 ( V_12 , V_2 , V_3 ) )
goto V_26;
if ( V_14 == V_27 )
V_19 = F_15 ( V_12 ) ;
else
V_19 = F_16 ( V_15 , V_3 , - 1 , NULL ,
V_17 , V_16 , V_12 ) ;
if ( ! V_19 || ! F_17 ( V_10 , V_19 ) )
goto V_26;
F_18 ( V_12 , V_33 ) ;
V_12 = NULL ;
}
V_20 = V_1 -> V_34 -> V_29 . V_35 ;
if ( ( V_1 -> V_34 -> V_29 . V_35 = F_19 () ) == NULL )
goto V_26;
if ( ! F_20 ( V_1 , V_10 ) )
goto V_26;
if ( ! F_21 ( V_1 , V_3 , - 1 , V_22 , & V_24 ) )
goto V_26;
F_22 ( V_1 -> V_22 -> V_36 , NULL , & V_21 ) ;
if ( ! F_23 ( V_21 , V_22 , V_24 ) )
goto V_26;
V_25 = 1 ;
V_26:
if ( V_25 == 1 ) {
F_24 ( V_20 ) ;
} else if ( V_20 != NULL ) {
F_24 ( V_1 -> V_34 -> V_29 . V_35 ) ;
V_1 -> V_34 -> V_29 . V_35 = V_20 ;
}
F_18 ( V_12 , V_33 ) ;
F_25 ( V_9 , V_37 ) ;
F_25 ( V_10 , V_37 ) ;
return V_25 ;
}
static int F_26 ( V_11 * V_38 , const char * V_2 ,
const char * V_3 )
{
T_3 * V_39 ;
T_4 * V_40 ;
int V_41 , V_42 , V_43 ;
const T_5 * V_44 ;
if ( F_27 ( V_38 ) != V_45 )
return 1 ;
if ( ( V_39 = F_28 ( V_38 -> V_46 . V_47 , V_2 , - 1 ) ) == NULL )
return 0 ;
F_29 ( V_38 -> V_46 . V_47 , & V_44 , NULL ) ;
if ( ! F_13 ( V_44 , & V_41 , & V_43 , & V_42 ) )
return 0 ;
V_40 = F_30 ( V_41 , NULL , V_3 , - 1 , NULL , V_42 ,
V_43 , V_39 ) ;
F_31 ( V_39 ) ;
if ( V_40 == NULL )
return 0 ;
F_32 ( V_38 -> V_46 . V_47 ) ;
V_38 -> V_46 . V_47 = V_40 ;
return 1 ;
}
static int F_13 ( const T_5 * V_48 , int * V_49 , int * V_50 ,
int * V_51 )
{
T_6 * V_52 ;
V_52 = F_33 ( F_34 ( T_6 ) , V_48 -> V_53 ) ;
if ( ! V_52 )
return 0 ;
* V_49 = F_10 ( V_48 -> V_32 ) ;
* V_50 = F_35 ( V_52 -> V_54 ) ;
* V_51 = V_52 -> V_55 -> V_56 ;
F_36 ( V_52 ) ;
return 1 ;
}
