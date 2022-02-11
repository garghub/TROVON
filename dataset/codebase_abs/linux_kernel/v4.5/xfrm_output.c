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
static struct V_3 * F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = F_8 ( F_2 ( V_2 ) -> V_11 ) ;
F_9 ( V_2 ) ;
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_16 * V_16 = F_11 ( V_14 ) ;
if ( V_12 <= 0 )
goto V_17;
do {
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_18 ) ;
goto V_19;
}
V_12 = V_14 -> V_20 -> V_21 ( V_14 , V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_22 ) ;
goto V_19;
}
F_13 ( & V_14 -> V_23 ) ;
if ( F_14 ( V_14 -> V_24 . V_25 != V_26 ) ) {
F_12 ( V_16 , V_27 ) ;
V_12 = - V_28 ;
goto error;
}
V_12 = F_15 ( V_14 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_29 ) ;
goto error;
}
V_12 = V_14 -> V_30 -> V_31 ( V_14 , V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_32 ) ;
goto error;
}
V_14 -> V_33 . V_34 += V_2 -> V_35 ;
V_14 -> V_33 . V_36 ++ ;
F_16 ( & V_14 -> V_23 ) ;
F_17 ( V_2 ) ;
V_12 = V_14 -> type -> V_21 ( V_14 , V_2 ) ;
if ( V_12 == - V_37 )
goto V_38;
V_17:
if ( V_12 ) {
F_12 ( V_16 , V_39 ) ;
goto V_19;
}
V_4 = F_7 ( V_2 ) ;
if ( ! V_4 ) {
F_12 ( V_16 , V_18 ) ;
V_12 = - V_40 ;
goto V_19;
}
F_18 ( V_2 , V_4 ) ;
V_14 = V_4 -> V_15 ;
} while ( V_14 && ! ( V_14 -> V_20 -> V_41 & V_42 ) );
return 0 ;
error:
F_16 ( & V_14 -> V_23 ) ;
V_19:
F_19 ( V_2 ) ;
V_38:
return V_12 ;
}
int F_20 ( struct V_1 * V_2 , int V_12 )
{
struct V_16 * V_16 = F_11 ( F_2 ( V_2 ) -> V_15 ) ;
while ( F_21 ( ( V_12 = F_10 ( V_2 , V_12 ) ) == 0 ) ) {
F_22 ( V_2 ) ;
V_12 = F_2 ( V_2 ) -> V_43 -> V_44 ( V_16 , V_2 -> V_45 , V_2 ) ;
if ( F_14 ( V_12 != 1 ) )
goto V_38;
if ( ! F_2 ( V_2 ) -> V_15 )
return F_23 ( V_16 , V_2 -> V_45 , V_2 ) ;
V_12 = F_24 ( F_2 ( V_2 ) -> V_43 -> V_46 ,
V_47 , V_16 , V_2 -> V_45 , V_2 ,
NULL , F_2 ( V_2 ) -> V_7 , V_48 ) ;
if ( F_14 ( V_12 != 1 ) )
goto V_38;
}
if ( V_12 == - V_37 )
V_12 = 0 ;
V_38:
return V_12 ;
}
static int V_48 ( struct V_16 * V_16 , struct V_49 * V_45 , struct V_1 * V_2 )
{
return F_20 ( V_2 , 1 ) ;
}
static int F_25 ( struct V_16 * V_16 , struct V_49 * V_45 , struct V_1 * V_2 )
{
struct V_1 * V_50 ;
F_26 ( sizeof( * F_27 ( V_2 ) ) > V_51 ) ;
F_26 ( sizeof( * F_28 ( V_2 ) ) > V_51 ) ;
V_50 = F_29 ( V_2 , 0 ) ;
F_19 ( V_2 ) ;
if ( F_30 ( V_50 ) )
return F_31 ( V_50 ) ;
if ( V_50 == NULL )
return - V_28 ;
do {
struct V_1 * V_52 = V_50 -> V_53 ;
int V_12 ;
V_50 -> V_53 = NULL ;
V_12 = V_48 ( V_16 , V_45 , V_50 ) ;
if ( F_14 ( V_12 ) ) {
F_32 ( V_52 ) ;
return V_12 ;
}
V_50 = V_52 ;
} while ( V_50 );
return 0 ;
}
int F_33 ( struct V_49 * V_45 , struct V_1 * V_2 )
{
struct V_16 * V_16 = F_34 ( F_2 ( V_2 ) -> V_7 ) ;
int V_12 ;
if ( F_35 ( V_2 ) )
return F_25 ( V_16 , V_45 , V_2 ) ;
if ( V_2 -> V_54 == V_55 ) {
V_12 = F_36 ( V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_18 ) ;
F_19 ( V_2 ) ;
return V_12 ;
}
}
return V_48 ( V_16 , V_45 , V_2 ) ;
}
int F_37 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_56 * V_57 ;
if ( V_14 -> V_58 . V_46 == V_59 )
V_57 = F_38 ( V_14 ,
F_39 ( F_2 ( V_2 ) -> V_43 -> V_46 ) ) ;
else
V_57 = V_14 -> V_57 ;
if ( V_57 == NULL )
return - V_60 ;
return V_57 -> V_61 -> V_62 ( V_14 , V_2 ) ;
}
void F_40 ( struct V_1 * V_2 , int V_63 )
{
unsigned int V_64 ;
struct V_65 * V_61 ;
if ( V_2 -> V_66 == F_41 ( V_67 ) )
V_64 = V_68 ;
else if ( V_2 -> V_66 == F_41 ( V_69 ) )
V_64 = V_70 ;
else
return;
V_61 = F_42 ( V_64 ) ;
if ( ! V_61 )
return;
V_61 -> V_71 ( V_2 , V_63 ) ;
F_43 ( V_61 ) ;
}
