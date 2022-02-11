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
int V_15 ;
int V_16 = - 1 ;
struct V_1 * V_2 ;
int V_17 = - V_18 ;
int V_19 ;
F_2 ( V_3 , L_2 , V_11 -> V_20 , V_11 -> V_21 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_22 . V_23 ; V_15 ++ ) {
if ( F_7 ( & V_13 -> V_24 [ V_15 ] . V_22 ) ) {
V_16 = F_8 ( & V_13 -> V_24 [ V_15 ] . V_22 ) ;
V_19 = F_9 ( & V_13 -> V_24 [ V_15 ] . V_22 ) ;
break;
}
}
if ( V_16 == - 1 ) {
F_2 ( V_3 , L_3 ) ;
return - V_25 ;
}
if ( V_19 <= 0 ) {
F_2 ( V_3 , L_4 , V_19 ) ;
return - V_25 ;
}
if ( V_19 > V_26 ) {
F_2 ( V_3 , L_5 ,
V_19 , V_26 ) ;
V_19 = V_26 ;
}
V_2 = F_10 ( sizeof( struct V_1 ) , V_27 ) ;
if ( V_2 == NULL )
goto V_28;
V_2 -> V_6 = F_11 ( V_19 , V_27 ) ;
if ( V_2 -> V_6 == NULL )
goto V_28;
V_2 -> V_4 = F_12 ( 0 , V_27 ) ;
if ( ! V_2 -> V_4 )
goto V_28;
F_13 ( V_2 -> V_4 ,
V_11 ,
F_14 ( V_11 , V_16 ) ,
V_2 -> V_6 ,
V_19 ,
V_29 ,
V_2 ) ;
if ( V_11 -> V_20 && V_11 -> V_21 ) {
V_2 -> V_5 = F_11 ( strlen ( V_11 -> V_20 ) + 1 +
strlen ( V_11 -> V_21 ) + 1 , V_27 ) ;
if ( V_2 -> V_5 == NULL )
goto V_28;
strcpy ( V_2 -> V_5 , V_11 -> V_20 ) ;
strcat ( V_2 -> V_5 , L_6 ) ;
strcat ( V_2 -> V_5 , V_11 -> V_21 ) ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_16 = V_16 ;
if ( V_11 -> V_30 . V_31 != V_32 )
V_2 -> V_33 = 1 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_34 = 1 ;
F_15 ( & V_2 -> V_35 ) ;
F_16 ( & V_2 -> V_36 ) ;
F_16 ( & V_2 -> V_37 ) ;
F_17 ( V_3 , V_2 ) ;
V_17 = F_18 ( V_3 , & V_38 ) ;
if ( V_17 ) {
F_19 ( V_3 , L_7 ) ;
goto V_28;
}
V_2 -> V_39 . V_5 = V_2 -> V_5 ? V_2 -> V_5 : V_40 . V_5 ;
V_2 -> V_39 . V_41 = V_42 ;
V_2 -> V_39 . V_43 = 1024 + 1023 ;
V_2 -> V_44 = ( F_20 ( & V_2 -> V_39 ) == 0 ) ;
if ( ! V_2 -> V_44 )
F_19 ( V_3 , L_8 ) ;
F_21 ( V_11 ) ;
F_2 ( V_3 , L_9 , V_2 -> V_19 ) ;
return 0 ;
V_28:
F_17 ( V_3 , NULL ) ;
F_1 ( V_2 ) ;
return V_17 ;
}
static void F_22 ( struct V_7 * V_3 )
{
struct V_1 * V_2 ;
F_2 ( V_3 , L_10 ) ;
V_2 = F_23 ( V_3 ) ;
if ( ! V_2 ) {
F_2 ( V_3 , L_11 ) ;
return;
}
if ( V_2 -> V_44 )
F_24 ( & V_2 -> V_39 ) ;
F_25 ( V_3 , & V_38 ) ;
F_17 ( V_3 , NULL ) ;
F_26 ( & V_2 -> V_36 ) ;
V_2 -> V_34 = 0 ;
F_27 ( V_2 -> V_4 ) ;
if ( ! V_2 -> V_45 ) {
F_28 ( & V_2 -> V_36 ) ;
F_1 ( V_2 ) ;
} else
F_28 ( & V_2 -> V_36 ) ;
F_2 ( V_3 , L_12 ) ;
}
static int F_29 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
struct V_1 * V_2 ;
struct V_7 * V_3 ;
V_3 = F_30 ( & V_40 , F_31 ( V_46 ) ) ;
if ( ! V_3 )
return - V_25 ;
F_2 ( V_3 , L_13 ) ;
V_2 = F_23 ( V_3 ) ;
if ( ! V_2 ) {
F_2 ( V_3 , L_14 ) ;
return - V_25 ;
}
V_47 -> V_48 = V_2 ;
F_26 ( & V_2 -> V_36 ) ;
++ V_2 -> V_45 ;
F_28 ( & V_2 -> V_36 ) ;
F_2 ( V_3 , L_15 ) ;
return 0 ;
}
static int F_32 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
struct V_7 * V_3 ;
if ( V_2 == NULL )
return - V_25 ;
V_3 = V_2 -> V_3 ;
F_2 ( V_3 , L_16 ) ;
F_26 ( & V_2 -> V_36 ) ;
F_2 ( V_3 , L_17 , V_2 -> V_45 ) ;
if ( V_2 -> V_45 <= 0 ) {
F_2 ( V_3 , L_18 , V_2 -> V_45 ) ;
F_28 ( & V_2 -> V_36 ) ;
return - V_25 ;
}
-- V_2 -> V_45 ;
if ( ! V_2 -> V_34 ) {
if ( V_2 -> V_45 == 0 ) {
F_28 ( & V_2 -> V_36 ) ;
F_1 ( V_2 ) ;
} else
F_28 ( & V_2 -> V_36 ) ;
} else
F_28 ( & V_2 -> V_36 ) ;
F_2 ( V_3 , L_19 ) ;
return 0 ;
}
static void V_29 ( struct V_4 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_49 ;
int V_50 = V_4 -> V_50 ;
F_2 ( V_2 -> V_3 , L_20 , V_50 ) ;
if ( V_50 == 0 )
V_2 -> V_51 = V_4 -> V_52 ;
else
V_2 -> V_51 = 0 ;
V_2 -> V_53 = 0 ;
F_33 () ;
V_2 -> V_54 = false ;
F_34 ( & V_2 -> V_35 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
F_36 ( V_55 ) ;
int V_17 ;
bool V_56 ;
F_2 ( V_2 -> V_3 , L_21 ) ;
if ( V_2 -> V_51 != V_2 -> V_53 ) {
F_2 ( V_2 -> V_3 , L_22 ,
V_2 -> V_51 , V_2 -> V_53 ) ;
return 0 ;
}
if ( ! V_2 -> V_34 ) {
F_2 ( V_2 -> V_3 , L_23 ) ;
return - V_25 ;
}
V_17 = F_37 ( V_2 -> V_3 ) ;
if ( V_17 ) {
F_2 ( V_2 -> V_3 , L_24 , V_17 ) ;
return V_17 ;
}
V_2 -> V_54 = true ;
V_17 = F_38 ( V_2 -> V_4 , V_27 ) ;
if ( V_17 < 0 ) {
V_17 = F_39 ( V_17 ) ;
V_2 -> V_54 = false ;
goto V_28;
}
V_56 = V_2 -> V_33 ;
V_2 -> V_33 = true ;
V_17 = F_40 (
V_2 -> V_35 ,
! V_2 -> V_54 ,
( V_56 ? V_57 : V_58 ) ) ;
if ( V_17 < 0 )
goto V_28;
if ( V_17 == 0 )
V_17 = - V_59 ;
else
V_17 = V_2 -> V_51 ;
V_28:
F_41 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_3 , L_25 , V_2 -> V_51 ) ;
return V_17 ;
}
static T_1 F_42 ( struct V_47 * V_47 ,
char T_2 * V_60 ,
T_3 V_61 ,
T_4 * V_62 )
{
struct V_1 * V_2 ;
T_1 V_63 = 0 ;
int V_64 ;
int V_17 = 0 ;
unsigned long V_65 ;
V_2 = V_47 -> V_48 ;
if ( V_2 == NULL || ! V_2 -> V_34 )
return - V_25 ;
F_2 ( V_2 -> V_3 , L_26 , V_61 ) ;
while ( V_61 > 0 ) {
V_17 = F_43 ( & V_2 -> V_37 ) ;
if ( V_17 )
goto V_66;
F_28 ( & V_2 -> V_37 ) ;
V_17 = F_43 ( & V_2 -> V_36 ) ;
if ( V_17 )
goto V_66;
if ( V_2 -> V_51 == V_2 -> V_53 ) {
V_17 = F_35 ( V_2 ) ;
if ( V_17 < 0 ) {
F_28 ( & V_2 -> V_36 ) ;
goto V_66;
}
}
V_64 = V_2 -> V_51 - V_2 -> V_53 ;
if ( V_64 > V_61 )
V_64 = V_61 ;
V_65 = F_44 ( V_60 , V_2 -> V_6 + V_2 -> V_53 , V_64 ) ;
if ( V_65 ) {
V_17 = - V_67 ;
V_2 -> V_53 += V_64 - V_65 ;
F_28 ( & V_2 -> V_36 ) ;
goto V_66;
}
V_61 -= V_64 ;
V_63 += V_64 ;
V_60 += V_64 ;
V_2 -> V_53 += V_64 ;
F_28 ( & V_2 -> V_36 ) ;
}
V_66:
if ( V_63 ) {
F_2 ( V_2 -> V_3 , L_27 , V_63 ) ;
return V_63 ;
}
F_2 ( V_2 -> V_3 , L_28 , V_17 ) ;
if ( V_17 == - V_59 )
V_17 = - V_68 ;
return V_17 ;
}
static int V_42 ( struct V_39 * V_69 , void * V_70 ,
T_3 V_71 , bool V_55 )
{
struct V_1 * V_2 = F_45 ( V_69 , struct V_1 , V_39 ) ;
int V_64 ;
F_2 ( V_2 -> V_3 , L_29 , V_71 , V_55 ) ;
if ( ! V_2 -> V_34 ) {
F_2 ( V_2 -> V_3 , L_23 ) ;
return 0 ;
}
F_26 ( & V_2 -> V_37 ) ;
F_26 ( & V_2 -> V_36 ) ;
F_28 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_51 == V_2 -> V_53 )
( void ) F_35 ( V_2 ) ;
V_64 = V_2 -> V_51 - V_2 -> V_53 ;
if ( V_64 > V_71 )
V_64 = V_71 ;
memcpy ( V_70 , V_2 -> V_6 + V_2 -> V_53 , V_64 ) ;
V_2 -> V_53 += V_64 ;
F_28 ( & V_2 -> V_36 ) ;
F_2 ( V_2 -> V_3 , L_30 , V_64 ) ;
return V_64 ;
}
static int F_46 ( struct V_7 * V_3 ,
T_5 V_72 )
{
F_2 ( V_3 , L_31 ) ;
return 0 ;
}
static int F_47 ( struct V_7 * V_3 )
{
F_2 ( V_3 , L_32 ) ;
return 0 ;
}
