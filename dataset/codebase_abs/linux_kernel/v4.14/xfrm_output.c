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
if ( V_14 -> V_20 . V_21 )
V_2 -> V_22 = V_14 -> V_20 . V_21 ;
V_12 = V_14 -> V_23 -> V_24 ( V_14 , V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_25 ) ;
goto V_19;
}
F_13 ( & V_14 -> V_26 ) ;
if ( F_14 ( V_14 -> V_27 . V_28 != V_29 ) ) {
F_12 ( V_16 , V_30 ) ;
V_12 = - V_31 ;
goto error;
}
V_12 = F_15 ( V_14 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_32 ) ;
goto error;
}
V_12 = V_14 -> V_33 -> V_34 ( V_14 , V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_35 ) ;
goto error;
}
V_14 -> V_36 . V_37 += V_2 -> V_38 ;
V_14 -> V_36 . V_39 ++ ;
F_16 ( & V_14 -> V_26 ) ;
F_17 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
V_14 -> V_40 -> V_41 ( V_14 , V_2 ) ;
} else {
V_2 -> V_42 = 0 ;
V_12 = V_14 -> type -> V_24 ( V_14 , V_2 ) ;
if ( V_12 == - V_43 )
goto V_44;
}
V_17:
if ( V_12 ) {
F_12 ( V_16 , V_45 ) ;
goto V_19;
}
V_4 = F_7 ( V_2 ) ;
if ( ! V_4 ) {
F_12 ( V_16 , V_18 ) ;
V_12 = - V_46 ;
goto V_19;
}
F_19 ( V_2 , V_4 ) ;
V_14 = V_4 -> V_15 ;
} while ( V_14 && ! ( V_14 -> V_23 -> V_47 & V_48 ) );
return 0 ;
error:
F_16 ( & V_14 -> V_26 ) ;
V_19:
F_20 ( V_2 ) ;
V_44:
return V_12 ;
}
int F_21 ( struct V_1 * V_2 , int V_12 )
{
struct V_16 * V_16 = F_11 ( F_2 ( V_2 ) -> V_15 ) ;
while ( F_22 ( ( V_12 = F_10 ( V_2 , V_12 ) ) == 0 ) ) {
F_23 ( V_2 ) ;
V_12 = F_2 ( V_2 ) -> V_49 -> V_50 ( V_16 , V_2 -> V_51 , V_2 ) ;
if ( F_14 ( V_12 != 1 ) )
goto V_44;
if ( ! F_2 ( V_2 ) -> V_15 )
return F_24 ( V_16 , V_2 -> V_51 , V_2 ) ;
V_12 = F_25 ( F_2 ( V_2 ) -> V_49 -> V_52 ,
V_53 , V_16 , V_2 -> V_51 , V_2 ,
NULL , F_2 ( V_2 ) -> V_7 , V_54 ) ;
if ( F_14 ( V_12 != 1 ) )
goto V_44;
}
if ( V_12 == - V_43 )
V_12 = 0 ;
V_44:
return V_12 ;
}
static int V_54 ( struct V_16 * V_16 , struct V_55 * V_51 , struct V_1 * V_2 )
{
return F_21 ( V_2 , 1 ) ;
}
static int F_26 ( struct V_16 * V_16 , struct V_55 * V_51 , struct V_1 * V_2 )
{
struct V_1 * V_56 ;
F_27 ( sizeof( * F_28 ( V_2 ) ) > V_57 ) ;
F_27 ( sizeof( * F_29 ( V_2 ) ) > V_57 ) ;
V_56 = F_30 ( V_2 , 0 ) ;
F_20 ( V_2 ) ;
if ( F_31 ( V_56 ) )
return F_32 ( V_56 ) ;
if ( V_56 == NULL )
return - V_31 ;
do {
struct V_1 * V_58 = V_56 -> V_59 ;
int V_12 ;
V_56 -> V_59 = NULL ;
V_12 = V_54 ( V_16 , V_51 , V_56 ) ;
if ( F_14 ( V_12 ) ) {
F_33 ( V_58 ) ;
return V_12 ;
}
V_56 = V_58 ;
} while ( V_56 );
return 0 ;
}
int F_34 ( struct V_55 * V_51 , struct V_1 * V_2 )
{
struct V_16 * V_16 = F_35 ( F_2 ( V_2 ) -> V_7 ) ;
struct V_13 * V_14 = F_2 ( V_2 ) -> V_15 ;
int V_12 ;
F_36 ( V_2 ) ;
if ( F_37 ( V_2 , V_14 ) ) {
struct V_60 * V_61 ;
V_61 = F_38 ( V_2 -> V_61 ) ;
if ( ! V_61 ) {
F_12 ( V_16 , V_18 ) ;
F_20 ( V_2 ) ;
return - V_62 ;
}
if ( V_2 -> V_61 )
F_39 ( V_2 -> V_61 ) ;
V_2 -> V_61 = V_61 ;
V_2 -> V_42 = 1 ;
V_61 -> V_63 ++ ;
V_61 -> V_64 [ V_2 -> V_61 -> V_38 ++ ] = V_14 ;
F_40 ( V_14 ) ;
if ( F_41 ( V_2 ) ) {
F_42 ( V_2 ) -> V_65 |= V_66 ;
return V_54 ( V_16 , V_51 , V_2 ) ;
}
if ( V_14 -> V_67 . V_7 && V_14 -> V_67 . V_7 -> V_68 & V_69 )
goto V_44;
}
if ( F_41 ( V_2 ) )
return F_26 ( V_16 , V_51 , V_2 ) ;
if ( V_2 -> V_70 == V_71 ) {
V_12 = F_43 ( V_2 ) ;
if ( V_12 ) {
F_12 ( V_16 , V_18 ) ;
F_20 ( V_2 ) ;
return V_12 ;
}
}
V_44:
return V_54 ( V_16 , V_51 , V_2 ) ;
}
int F_44 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_72 * V_73 ;
if ( V_14 -> V_74 . V_52 == V_75 )
V_73 = F_45 ( V_14 ,
F_46 ( F_2 ( V_2 ) -> V_49 -> V_52 ) ) ;
else
V_73 = V_14 -> V_73 ;
if ( V_73 == NULL )
return - V_76 ;
return V_73 -> V_77 -> V_78 ( V_14 , V_2 ) ;
}
void F_47 ( struct V_1 * V_2 , int V_79 )
{
unsigned int V_80 ;
struct V_81 * V_77 ;
if ( V_2 -> V_82 == F_48 ( V_83 ) )
V_80 = V_84 ;
else if ( V_2 -> V_82 == F_48 ( V_85 ) )
V_80 = V_86 ;
else
return;
V_77 = F_49 ( V_80 ) ;
if ( V_77 )
V_77 -> V_87 ( V_2 , V_79 ) ;
F_50 () ;
}
