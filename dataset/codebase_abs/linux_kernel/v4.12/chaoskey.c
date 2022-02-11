static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 , L_1 ) ;
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
}
}
static int F_5 ( struct V_7 * V_3 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_3 ) ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_15 * V_16 ;
int V_17 ;
struct V_1 * V_2 ;
int V_18 = - V_19 ;
int V_20 ;
int V_21 ;
F_2 ( V_3 , L_2 , V_11 -> V_22 , V_11 -> V_23 ) ;
V_21 = F_7 ( V_13 , & V_16 ) ;
if ( V_21 ) {
F_2 ( V_3 , L_3 ) ;
return V_21 ;
}
V_17 = F_8 ( V_16 ) ;
V_20 = F_9 ( V_16 ) ;
if ( V_20 <= 0 ) {
F_2 ( V_3 , L_4 , V_20 ) ;
return - V_24 ;
}
if ( V_20 > V_25 ) {
F_2 ( V_3 , L_5 ,
V_20 , V_25 ) ;
V_20 = V_25 ;
}
V_2 = F_10 ( sizeof( struct V_1 ) , V_26 ) ;
if ( V_2 == NULL )
goto V_27;
V_2 -> V_6 = F_11 ( V_20 , V_26 ) ;
if ( V_2 -> V_6 == NULL )
goto V_27;
V_2 -> V_4 = F_12 ( 0 , V_26 ) ;
if ( ! V_2 -> V_4 )
goto V_27;
F_13 ( V_2 -> V_4 ,
V_11 ,
F_14 ( V_11 , V_17 ) ,
V_2 -> V_6 ,
V_20 ,
V_28 ,
V_2 ) ;
if ( V_11 -> V_22 && V_11 -> V_23 ) {
V_2 -> V_5 = F_11 ( strlen ( V_11 -> V_22 ) + 1 +
strlen ( V_11 -> V_23 ) + 1 , V_26 ) ;
if ( V_2 -> V_5 == NULL )
goto V_27;
strcpy ( V_2 -> V_5 , V_11 -> V_22 ) ;
strcat ( V_2 -> V_5 , L_6 ) ;
strcat ( V_2 -> V_5 , V_11 -> V_23 ) ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_17 = V_17 ;
if ( F_15 ( V_11 -> V_29 . V_30 ) != V_31 )
V_2 -> V_32 = 1 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_33 = 1 ;
F_16 ( & V_2 -> V_34 ) ;
F_17 ( & V_2 -> V_35 ) ;
F_17 ( & V_2 -> V_36 ) ;
F_18 ( V_3 , V_2 ) ;
V_18 = F_19 ( V_3 , & V_37 ) ;
if ( V_18 ) {
F_20 ( V_3 , L_7 ) ;
goto V_27;
}
V_2 -> V_38 . V_5 = V_2 -> V_5 ? V_2 -> V_5 : V_39 . V_5 ;
V_2 -> V_38 . V_40 = V_41 ;
V_2 -> V_38 . V_42 = 1024 ;
V_2 -> V_43 = ( F_21 ( & V_2 -> V_38 ) == 0 ) ;
if ( ! V_2 -> V_43 )
F_20 ( V_3 , L_8 ) ;
F_22 ( V_11 ) ;
F_2 ( V_3 , L_9 , V_2 -> V_20 ) ;
return 0 ;
V_27:
F_18 ( V_3 , NULL ) ;
F_1 ( V_2 ) ;
return V_18 ;
}
static void F_23 ( struct V_7 * V_3 )
{
struct V_1 * V_2 ;
F_2 ( V_3 , L_10 ) ;
V_2 = F_24 ( V_3 ) ;
if ( ! V_2 ) {
F_2 ( V_3 , L_11 ) ;
return;
}
if ( V_2 -> V_43 )
F_25 ( & V_2 -> V_38 ) ;
F_26 ( V_3 , & V_37 ) ;
F_18 ( V_3 , NULL ) ;
F_27 ( & V_2 -> V_35 ) ;
V_2 -> V_33 = 0 ;
F_28 ( V_2 -> V_4 ) ;
if ( ! V_2 -> V_44 ) {
F_29 ( & V_2 -> V_35 ) ;
F_1 ( V_2 ) ;
} else
F_29 ( & V_2 -> V_35 ) ;
F_2 ( V_3 , L_12 ) ;
}
static int F_30 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_1 * V_2 ;
struct V_7 * V_3 ;
V_3 = F_31 ( & V_39 , F_32 ( V_45 ) ) ;
if ( ! V_3 )
return - V_24 ;
F_2 ( V_3 , L_13 ) ;
V_2 = F_24 ( V_3 ) ;
if ( ! V_2 ) {
F_2 ( V_3 , L_14 ) ;
return - V_24 ;
}
V_46 -> V_47 = V_2 ;
F_27 ( & V_2 -> V_35 ) ;
++ V_2 -> V_44 ;
F_29 ( & V_2 -> V_35 ) ;
F_2 ( V_3 , L_15 ) ;
return 0 ;
}
static int F_33 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_47 ;
struct V_7 * V_3 ;
if ( V_2 == NULL )
return - V_24 ;
V_3 = V_2 -> V_3 ;
F_2 ( V_3 , L_16 ) ;
F_27 ( & V_2 -> V_35 ) ;
F_2 ( V_3 , L_17 , V_2 -> V_44 ) ;
if ( V_2 -> V_44 <= 0 ) {
F_2 ( V_3 , L_18 , V_2 -> V_44 ) ;
F_29 ( & V_2 -> V_35 ) ;
return - V_24 ;
}
-- V_2 -> V_44 ;
if ( ! V_2 -> V_33 ) {
if ( V_2 -> V_44 == 0 ) {
F_29 ( & V_2 -> V_35 ) ;
F_1 ( V_2 ) ;
} else
F_29 ( & V_2 -> V_35 ) ;
} else
F_29 ( & V_2 -> V_35 ) ;
F_2 ( V_3 , L_19 ) ;
return 0 ;
}
static void V_28 ( struct V_4 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
int V_49 = V_4 -> V_49 ;
F_2 ( V_2 -> V_3 , L_20 , V_49 ) ;
if ( V_49 == 0 )
V_2 -> V_50 = V_4 -> V_51 ;
else
V_2 -> V_50 = 0 ;
V_2 -> V_52 = 0 ;
F_34 () ;
V_2 -> V_53 = false ;
F_35 ( & V_2 -> V_34 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_37 ( V_54 ) ;
int V_18 ;
bool V_55 ;
F_2 ( V_2 -> V_3 , L_21 ) ;
if ( V_2 -> V_50 != V_2 -> V_52 ) {
F_2 ( V_2 -> V_3 , L_22 ,
V_2 -> V_50 , V_2 -> V_52 ) ;
return 0 ;
}
if ( ! V_2 -> V_33 ) {
F_2 ( V_2 -> V_3 , L_23 ) ;
return - V_24 ;
}
V_18 = F_38 ( V_2 -> V_3 ) ;
if ( V_18 ) {
F_2 ( V_2 -> V_3 , L_24 , V_18 ) ;
return V_18 ;
}
V_2 -> V_53 = true ;
V_18 = F_39 ( V_2 -> V_4 , V_26 ) ;
if ( V_18 < 0 ) {
V_18 = F_40 ( V_18 ) ;
V_2 -> V_53 = false ;
goto V_27;
}
V_55 = V_2 -> V_32 ;
V_2 -> V_32 = true ;
V_18 = F_41 (
V_2 -> V_34 ,
! V_2 -> V_53 ,
( V_55 ? V_56 : V_57 ) ) ;
if ( V_18 < 0 )
goto V_27;
if ( V_18 == 0 )
V_18 = - V_58 ;
else
V_18 = V_2 -> V_50 ;
V_27:
F_42 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_3 , L_25 , V_2 -> V_50 ) ;
return V_18 ;
}
static T_1 F_43 ( struct V_46 * V_46 ,
char T_2 * V_59 ,
T_3 V_60 ,
T_4 * V_61 )
{
struct V_1 * V_2 ;
T_1 V_62 = 0 ;
int V_63 ;
int V_18 = 0 ;
unsigned long V_64 ;
V_2 = V_46 -> V_47 ;
if ( V_2 == NULL || ! V_2 -> V_33 )
return - V_24 ;
F_2 ( V_2 -> V_3 , L_26 , V_60 ) ;
while ( V_60 > 0 ) {
V_18 = F_44 ( & V_2 -> V_36 ) ;
if ( V_18 )
goto V_65;
F_29 ( & V_2 -> V_36 ) ;
V_18 = F_44 ( & V_2 -> V_35 ) ;
if ( V_18 )
goto V_65;
if ( V_2 -> V_50 == V_2 -> V_52 ) {
V_18 = F_36 ( V_2 ) ;
if ( V_18 < 0 ) {
F_29 ( & V_2 -> V_35 ) ;
goto V_65;
}
}
V_63 = V_2 -> V_50 - V_2 -> V_52 ;
if ( V_63 > V_60 )
V_63 = V_60 ;
V_64 = F_45 ( V_59 , V_2 -> V_6 + V_2 -> V_52 , V_63 ) ;
if ( V_64 ) {
V_18 = - V_66 ;
V_2 -> V_52 += V_63 - V_64 ;
F_29 ( & V_2 -> V_35 ) ;
goto V_65;
}
V_60 -= V_63 ;
V_62 += V_63 ;
V_59 += V_63 ;
V_2 -> V_52 += V_63 ;
F_29 ( & V_2 -> V_35 ) ;
}
V_65:
if ( V_62 ) {
F_2 ( V_2 -> V_3 , L_27 , V_62 ) ;
return V_62 ;
}
F_2 ( V_2 -> V_3 , L_28 , V_18 ) ;
if ( V_18 == - V_58 )
V_18 = - V_67 ;
return V_18 ;
}
static int V_41 ( struct V_38 * V_68 , void * V_69 ,
T_3 V_70 , bool V_54 )
{
struct V_1 * V_2 = F_46 ( V_68 , struct V_1 , V_38 ) ;
int V_63 ;
F_2 ( V_2 -> V_3 , L_29 , V_70 , V_54 ) ;
if ( ! V_2 -> V_33 ) {
F_2 ( V_2 -> V_3 , L_23 ) ;
return 0 ;
}
F_27 ( & V_2 -> V_36 ) ;
F_27 ( & V_2 -> V_35 ) ;
F_29 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_50 == V_2 -> V_52 )
( void ) F_36 ( V_2 ) ;
V_63 = V_2 -> V_50 - V_2 -> V_52 ;
if ( V_63 > V_70 )
V_63 = V_70 ;
memcpy ( V_69 , V_2 -> V_6 + V_2 -> V_52 , V_63 ) ;
V_2 -> V_52 += V_63 ;
F_29 ( & V_2 -> V_35 ) ;
F_2 ( V_2 -> V_3 , L_30 , V_63 ) ;
return V_63 ;
}
static int F_47 ( struct V_7 * V_3 ,
T_5 V_71 )
{
F_2 ( V_3 , L_31 ) ;
return 0 ;
}
static int F_48 ( struct V_7 * V_3 )
{
F_2 ( V_3 , L_32 ) ;
return 0 ;
}
