static int F_1 ( T_1 * V_1 ,
T_2 * V_2 , int V_3 )
{
int V_4 ;
int V_5 = 0 ;
T_3 * V_6 = V_1 -> V_7 ;
T_4 * V_8 = NULL ;
T_5 * V_9 ;
if ( F_2 ( V_2 ) == 0 )
goto V_10;
V_6 -> V_8 = F_3 ( V_11 ) ;
if ( ! V_6 -> V_8 )
goto V_10;
for ( V_4 = 0 ; V_4 < F_2 ( V_2 ) ; V_4 ++ ) {
V_9 = F_4 ( V_2 , V_4 ) ;
V_8 = F_5 ( V_9 , NULL , V_3 ) ;
if ( ! V_8 )
goto V_10;
if ( F_6 ( V_8 -> V_12 ) == V_13 ) {
if ( V_6 -> V_14 ) {
V_5 = - 1 ;
goto V_10;
}
V_6 -> V_14 = V_8 ;
} else if ( F_7 ( V_6 -> V_8 , V_8 ) != - 1 ) {
V_5 = - 1 ;
goto V_10;
} else if ( ! F_8 ( V_6 -> V_8 , V_8 ) )
goto V_10;
V_8 = NULL ;
}
V_5 = 1 ;
V_10:
if ( V_5 == - 1 )
V_1 -> V_15 |= V_16 ;
if ( V_8 )
F_9 ( V_8 ) ;
F_10 ( V_2 , V_17 ) ;
if ( V_5 <= 0 ) {
F_11 ( V_6 -> V_8 , F_9 ) ;
V_6 -> V_8 = NULL ;
}
return V_5 ;
}
static int F_12 ( T_1 * V_1 )
{
T_3 * V_6 ;
T_6 * V_18 = NULL ;
T_7 * V_19 = NULL ;
T_2 * V_20 = NULL ;
T_8 * V_21 = NULL ;
int V_4 ;
V_6 = F_13 ( sizeof( T_3 ) ) ;
if ( ! V_6 )
return 0 ;
V_6 -> V_14 = NULL ;
V_6 -> V_8 = NULL ;
V_6 -> V_22 = - 1 ;
V_6 -> V_23 = - 1 ;
V_6 -> V_24 = - 1 ;
V_1 -> V_7 = V_6 ;
V_19 = F_14 ( V_1 , V_25 , & V_4 , NULL ) ;
if ( ! V_19 ) {
if ( V_4 != - 1 )
goto V_26;
} else {
if ( ! V_19 -> V_27
&& ! V_19 -> V_28 )
goto V_26;
if ( ! F_15 ( & V_6 -> V_23 ,
V_19 -> V_27 ) )
goto V_26;
if ( ! F_15 ( & V_6 -> V_24 ,
V_19 -> V_28 ) )
goto V_26;
}
V_20 = F_14 ( V_1 , V_29 , & V_4 , NULL ) ;
if ( ! V_20 ) {
if ( V_4 != - 1 )
goto V_26;
return 1 ;
}
V_4 = F_1 ( V_1 , V_20 , V_4 ) ;
if ( V_4 <= 0 )
return V_4 ;
V_21 = F_14 ( V_1 , V_30 , & V_4 , NULL ) ;
if ( ! V_21 ) {
if ( V_4 != - 1 )
goto V_26;
} else {
V_4 = F_16 ( V_1 , V_21 ) ;
if ( V_4 <= 0 )
goto V_26;
}
V_18 = F_14 ( V_1 , V_31 , & V_4 , NULL ) ;
if ( ! V_18 ) {
if ( V_4 != - 1 )
goto V_26;
} else if ( ! F_15 ( & V_6 -> V_22 , V_18 ) )
goto V_26;
if ( 0 ) {
V_26:
V_1 -> V_15 |= V_16 ;
}
if ( V_19 )
F_17 ( V_19 ) ;
if ( V_18 )
F_18 ( V_18 ) ;
return 1 ;
}
void F_19 ( T_3 * V_6 )
{
if ( ! V_6 )
return;
if ( V_6 -> V_14 )
F_9 ( V_6 -> V_14 ) ;
if ( V_6 -> V_8 )
F_11 ( V_6 -> V_8 , F_9 ) ;
F_20 ( V_6 ) ;
}
const T_3 * F_21 ( T_1 * V_1 )
{
if ( V_1 -> V_7 == NULL ) {
F_22 ( V_32 ) ;
F_12 ( V_1 ) ;
F_23 ( V_32 ) ;
}
return V_1 -> V_7 ;
}
T_4 * F_24 ( const T_3 * V_6 ,
const T_9 * V_33 )
{
int V_34 ;
T_4 V_35 ;
V_35 . V_12 = ( T_9 * ) V_33 ;
V_34 = F_7 ( V_6 -> V_8 , & V_35 ) ;
if ( V_34 == - 1 )
return NULL ;
return F_25 ( V_6 -> V_8 , V_34 ) ;
}
static int V_11 ( const T_4 * const * V_36 ,
const T_4 * const * V_37 )
{
return F_26 ( ( * V_36 ) -> V_12 , ( * V_37 ) -> V_12 ) ;
}
static int F_15 ( long * V_38 , T_6 * V_39 )
{
if ( V_39 == NULL )
return 1 ;
if ( V_39 -> type == V_40 )
return 0 ;
* V_38 = F_27 ( V_39 ) ;
return 1 ;
}
