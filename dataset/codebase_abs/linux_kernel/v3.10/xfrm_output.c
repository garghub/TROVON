static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_6 + F_3 ( V_4 -> V_7 )
- F_4 ( V_2 ) ;
int V_8 = V_4 -> V_7 -> V_9 - F_5 ( V_2 ) ;
if ( V_5 <= 0 ) {
if ( V_8 <= 0 )
return 0 ;
V_5 = 0 ;
} else if ( V_8 < 0 )
V_8 = 0 ;
return F_6 ( V_2 , V_5 , V_8 , V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_15 * V_15 = F_8 ( V_13 ) ;
if ( V_11 <= 0 )
goto V_16;
do {
V_11 = F_1 ( V_2 ) ;
if ( V_11 ) {
F_9 ( V_15 , V_17 ) ;
goto V_18;
}
V_11 = V_13 -> V_19 -> V_20 ( V_13 , V_2 ) ;
if ( V_11 ) {
F_9 ( V_15 , V_21 ) ;
goto V_18;
}
F_10 ( & V_13 -> V_22 ) ;
if ( F_11 ( V_13 -> V_23 . V_24 != V_25 ) ) {
F_9 ( V_15 , V_26 ) ;
V_11 = - V_27 ;
goto error;
}
V_11 = F_12 ( V_13 ) ;
if ( V_11 ) {
F_9 ( V_15 , V_28 ) ;
goto error;
}
V_11 = V_13 -> V_29 -> V_30 ( V_13 , V_2 ) ;
if ( V_11 ) {
F_9 ( V_15 , V_31 ) ;
goto error;
}
V_13 -> V_32 . V_33 += V_2 -> V_34 ;
V_13 -> V_32 . V_35 ++ ;
F_13 ( & V_13 -> V_22 ) ;
F_14 ( V_2 ) ;
V_11 = V_13 -> type -> V_20 ( V_13 , V_2 ) ;
if ( V_11 == - V_36 )
goto V_37;
V_16:
if ( V_11 ) {
F_9 ( V_15 , V_38 ) ;
goto V_18;
}
V_4 = F_15 ( V_2 ) ;
if ( ! V_4 ) {
F_9 ( V_15 , V_17 ) ;
V_11 = - V_39 ;
goto V_18;
}
F_16 ( V_2 , V_4 ) ;
V_13 = V_4 -> V_14 ;
} while ( V_13 && ! ( V_13 -> V_19 -> V_40 & V_41 ) );
V_11 = 0 ;
V_37:
return V_11 ;
error:
F_13 ( & V_13 -> V_22 ) ;
V_18:
F_17 ( V_2 ) ;
goto V_37;
}
int F_18 ( struct V_1 * V_2 , int V_11 )
{
while ( F_19 ( ( V_11 = F_7 ( V_2 , V_11 ) ) == 0 ) ) {
F_20 ( V_2 ) ;
V_11 = F_2 ( V_2 ) -> V_42 -> V_43 ( V_2 ) ;
if ( F_11 ( V_11 != 1 ) )
goto V_44;
if ( ! F_2 ( V_2 ) -> V_14 )
return F_21 ( V_2 ) ;
V_11 = F_22 ( F_2 ( V_2 ) -> V_42 -> V_45 ,
V_46 , V_2 ,
NULL , F_2 ( V_2 ) -> V_7 , V_47 ) ;
if ( F_11 ( V_11 != 1 ) )
goto V_44;
}
if ( V_11 == - V_36 )
V_11 = 0 ;
V_44:
return V_11 ;
}
static int V_47 ( struct V_1 * V_2 )
{
return F_18 ( V_2 , 1 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_1 * V_48 ;
V_48 = F_24 ( V_2 , 0 ) ;
F_17 ( V_2 ) ;
if ( F_25 ( V_48 ) )
return F_26 ( V_48 ) ;
do {
struct V_1 * V_49 = V_48 -> V_50 ;
int V_11 ;
V_48 -> V_50 = NULL ;
V_11 = V_47 ( V_48 ) ;
if ( F_11 ( V_11 ) ) {
while ( ( V_48 = V_49 ) ) {
V_49 = V_48 -> V_50 ;
V_48 -> V_50 = NULL ;
F_17 ( V_48 ) ;
}
return V_11 ;
}
V_48 = V_49 ;
} while ( V_48 );
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_28 ( F_2 ( V_2 ) -> V_7 ) ;
int V_11 ;
if ( F_29 ( V_2 ) )
return F_23 ( V_2 ) ;
if ( V_2 -> V_51 == V_52 ) {
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_9 ( V_15 , V_17 ) ;
F_17 ( V_2 ) ;
return V_11 ;
}
}
return V_47 ( V_2 ) ;
}
int F_31 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_53 * V_54 ;
if ( V_13 -> V_55 . V_45 == V_56 )
V_54 = F_32 ( V_13 ,
F_33 ( F_2 ( V_2 ) -> V_42 -> V_45 ) ) ;
else
V_54 = V_13 -> V_54 ;
if ( V_54 == NULL )
return - V_57 ;
return V_54 -> V_58 -> V_59 ( V_13 , V_2 ) ;
}
