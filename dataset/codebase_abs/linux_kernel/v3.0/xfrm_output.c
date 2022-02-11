static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = V_6 -> V_8 + F_3 ( V_6 -> V_9 )
- F_4 ( V_4 ) ;
int V_10 = V_6 -> V_9 -> V_11 - F_5 ( V_4 ) ;
if ( V_7 <= 0 ) {
if ( V_10 <= 0 )
return 0 ;
V_7 = 0 ;
} else if ( V_10 < 0 )
V_10 = 0 ;
return F_6 ( V_4 , V_7 , V_10 , V_12 ) ;
}
static int F_7 ( struct V_3 * V_4 , int V_13 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_6 -> V_14 ;
struct V_15 * V_15 = F_8 ( V_2 ) ;
if ( V_13 <= 0 )
goto V_16;
do {
V_13 = F_1 ( V_2 , V_4 ) ;
if ( V_13 ) {
F_9 ( V_15 , V_17 ) ;
goto V_18;
}
V_13 = V_2 -> V_19 -> V_20 ( V_2 , V_4 ) ;
if ( V_13 ) {
F_9 ( V_15 , V_21 ) ;
goto V_18;
}
F_10 ( & V_2 -> V_22 ) ;
V_13 = F_11 ( V_2 ) ;
if ( V_13 ) {
F_9 ( V_15 , V_23 ) ;
goto error;
}
V_13 = V_2 -> V_24 -> V_25 ( V_2 , V_4 ) ;
if ( V_13 ) {
F_9 ( V_15 , V_26 ) ;
goto error;
}
V_2 -> V_27 . V_28 += V_4 -> V_29 ;
V_2 -> V_27 . V_30 ++ ;
F_12 ( & V_2 -> V_22 ) ;
F_13 ( V_4 ) ;
V_13 = V_2 -> type -> V_20 ( V_2 , V_4 ) ;
if ( V_13 == - V_31 )
goto V_32;
V_16:
if ( V_13 ) {
F_9 ( V_15 , V_33 ) ;
goto V_18;
}
V_6 = F_14 ( V_4 ) ;
if ( ! V_6 ) {
F_9 ( V_15 , V_17 ) ;
V_13 = - V_34 ;
goto V_18;
}
F_15 ( V_4 , V_6 ) ;
V_2 = V_6 -> V_14 ;
} while ( V_2 && ! ( V_2 -> V_19 -> V_35 & V_36 ) );
V_13 = 0 ;
V_32:
return V_13 ;
error:
F_12 ( & V_2 -> V_22 ) ;
V_18:
F_16 ( V_4 ) ;
goto V_32;
}
int F_17 ( struct V_3 * V_4 , int V_13 )
{
while ( F_18 ( ( V_13 = F_7 ( V_4 , V_13 ) ) == 0 ) ) {
F_19 ( V_4 ) ;
V_13 = F_2 ( V_4 ) -> V_37 -> V_38 ( V_4 ) ;
if ( F_20 ( V_13 != 1 ) )
goto V_39;
if ( ! F_2 ( V_4 ) -> V_14 )
return F_21 ( V_4 ) ;
V_13 = F_22 ( F_2 ( V_4 ) -> V_37 -> V_40 ,
V_41 , V_4 ,
NULL , F_2 ( V_4 ) -> V_9 , V_42 ) ;
if ( F_20 ( V_13 != 1 ) )
goto V_39;
}
if ( V_13 == - V_31 )
V_13 = 0 ;
V_39:
return V_13 ;
}
static int V_42 ( struct V_3 * V_4 )
{
return F_17 ( V_4 , 1 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_3 * V_43 ;
V_43 = F_24 ( V_4 , 0 ) ;
F_16 ( V_4 ) ;
if ( F_25 ( V_43 ) )
return F_26 ( V_43 ) ;
do {
struct V_3 * V_44 = V_43 -> V_45 ;
int V_13 ;
V_43 -> V_45 = NULL ;
V_13 = V_42 ( V_43 ) ;
if ( F_20 ( V_13 ) ) {
while ( ( V_43 = V_44 ) ) {
V_44 = V_43 -> V_45 ;
V_43 -> V_45 = NULL ;
F_16 ( V_43 ) ;
}
return V_13 ;
}
V_43 = V_44 ;
} while ( V_43 );
return 0 ;
}
int F_27 ( struct V_3 * V_4 )
{
struct V_15 * V_15 = F_28 ( F_2 ( V_4 ) -> V_9 ) ;
int V_13 ;
if ( F_29 ( V_4 ) )
return F_23 ( V_4 ) ;
if ( V_4 -> V_46 == V_47 ) {
V_13 = F_30 ( V_4 ) ;
if ( V_13 ) {
F_9 ( V_15 , V_17 ) ;
F_16 ( V_4 ) ;
return V_13 ;
}
}
return V_42 ( V_4 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_48 * V_49 ;
if ( V_2 -> V_50 . V_40 == V_51 )
V_49 = F_32 ( V_2 ,
F_33 ( F_2 ( V_4 ) -> V_37 -> V_40 ) ) ;
else
V_49 = V_2 -> V_49 ;
if ( V_49 == NULL )
return - V_52 ;
return V_49 -> V_53 -> V_54 ( V_2 , V_4 ) ;
}
