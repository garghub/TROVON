static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_6 * V_3 ,
const struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_13 ;
int V_14 ;
int V_15 = - 1 ;
struct V_1 * V_2 ;
int V_16 ;
int V_17 ;
F_2 ( V_3 , L_2 , V_10 -> V_18 , V_10 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_20 . V_21 ; V_14 ++ ) {
if ( F_6 ( & V_12 -> V_22 [ V_14 ] . V_20 ) ) {
V_15 = F_7 ( & V_12 -> V_22 [ V_14 ] . V_20 ) ;
V_17 = F_8 ( & V_12 -> V_22 [ V_14 ] . V_20 ) ;
break;
}
}
if ( V_15 == - 1 ) {
F_2 ( V_3 , L_3 ) ;
return - V_23 ;
}
if ( V_17 <= 0 ) {
F_2 ( V_3 , L_4 , V_17 ) ;
return - V_23 ;
}
if ( V_17 > V_24 ) {
F_2 ( V_3 , L_5 ,
V_17 , V_24 ) ;
V_17 = V_24 ;
}
V_2 = F_9 ( sizeof( struct V_1 ) , V_25 ) ;
if ( V_2 == NULL )
return - V_26 ;
V_2 -> V_5 = F_10 ( V_17 , V_25 ) ;
if ( V_2 -> V_5 == NULL ) {
F_3 ( V_2 ) ;
return - V_26 ;
}
if ( V_10 -> V_18 && V_10 -> V_19 ) {
V_2 -> V_4 = F_10 ( strlen ( V_10 -> V_18 ) + 1 +
strlen ( V_10 -> V_19 ) + 1 , V_25 ) ;
if ( V_2 -> V_4 == NULL ) {
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 ) ;
return - V_26 ;
}
strcpy ( V_2 -> V_4 , V_10 -> V_18 ) ;
strcat ( V_2 -> V_4 , L_6 ) ;
strcat ( V_2 -> V_4 , V_10 -> V_19 ) ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_27 = 1 ;
F_11 ( & V_2 -> V_28 ) ;
F_12 ( & V_2 -> V_29 ) ;
F_12 ( & V_2 -> V_30 ) ;
F_13 ( V_3 , V_2 ) ;
V_16 = F_14 ( V_3 , & V_31 ) ;
if ( V_16 ) {
F_15 ( V_3 , L_7 ) ;
F_13 ( V_3 , NULL ) ;
F_1 ( V_2 ) ;
return V_16 ;
}
V_2 -> V_32 . V_4 = V_2 -> V_4 ? V_2 -> V_4 : V_33 . V_4 ;
V_2 -> V_32 . V_34 = V_35 ;
V_2 -> V_32 . V_36 = 1024 + 1023 ;
V_2 -> V_37 = ( F_16 ( & V_2 -> V_32 ) == 0 ) ;
if ( ! V_2 -> V_37 )
F_15 ( V_3 , L_8 ) ;
F_17 ( V_10 ) ;
F_2 ( V_3 , L_9 , V_2 -> V_17 ) ;
return 0 ;
}
static void F_18 ( struct V_6 * V_3 )
{
struct V_1 * V_2 ;
F_2 ( V_3 , L_10 ) ;
V_2 = F_19 ( V_3 ) ;
if ( ! V_2 ) {
F_2 ( V_3 , L_11 ) ;
return;
}
if ( V_2 -> V_37 )
F_20 ( & V_2 -> V_32 ) ;
F_21 ( V_3 , & V_31 ) ;
F_13 ( V_3 , NULL ) ;
F_22 ( & V_2 -> V_29 ) ;
V_2 -> V_27 = 0 ;
if ( ! V_2 -> V_38 ) {
F_23 ( & V_2 -> V_29 ) ;
F_1 ( V_2 ) ;
} else
F_23 ( & V_2 -> V_29 ) ;
F_2 ( V_3 , L_12 ) ;
}
static int F_24 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
struct V_1 * V_2 ;
struct V_6 * V_3 ;
V_3 = F_25 ( & V_33 , F_26 ( V_39 ) ) ;
if ( ! V_3 )
return - V_23 ;
F_2 ( V_3 , L_13 ) ;
V_2 = F_19 ( V_3 ) ;
if ( ! V_2 ) {
F_2 ( V_3 , L_14 ) ;
return - V_23 ;
}
V_40 -> V_41 = V_2 ;
F_22 ( & V_2 -> V_29 ) ;
++ V_2 -> V_38 ;
F_23 ( & V_2 -> V_29 ) ;
F_2 ( V_3 , L_15 ) ;
return 0 ;
}
static int F_27 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
struct V_6 * V_3 ;
if ( V_2 == NULL )
return - V_23 ;
V_3 = V_2 -> V_3 ;
F_2 ( V_3 , L_16 ) ;
F_22 ( & V_2 -> V_29 ) ;
F_2 ( V_3 , L_17 , V_2 -> V_38 ) ;
if ( V_2 -> V_38 <= 0 ) {
F_2 ( V_3 , L_18 , V_2 -> V_38 ) ;
F_23 ( & V_2 -> V_29 ) ;
return - V_23 ;
}
-- V_2 -> V_38 ;
if ( ! V_2 -> V_27 ) {
if ( V_2 -> V_38 == 0 ) {
F_23 ( & V_2 -> V_29 ) ;
F_1 ( V_2 ) ;
} else
F_23 ( & V_2 -> V_29 ) ;
} else
F_23 ( & V_2 -> V_29 ) ;
F_2 ( V_3 , L_19 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_29 ( V_42 ) ;
int V_16 ;
int V_43 ;
struct V_9 * V_10 = F_5 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_3 , L_20 ) ;
if ( V_2 -> V_44 != V_2 -> V_45 ) {
F_2 ( V_2 -> V_3 , L_21 ,
V_2 -> V_44 , V_2 -> V_45 ) ;
return 0 ;
}
if ( ! V_2 -> V_27 ) {
F_2 ( V_2 -> V_3 , L_22 ) ;
return - V_23 ;
}
V_16 = F_30 ( V_2 -> V_3 ) ;
if ( V_16 ) {
F_2 ( V_2 -> V_3 , L_23 , V_16 ) ;
return V_16 ;
}
V_16 = F_31 ( V_10 ,
F_32 ( V_10 , V_2 -> V_15 ) ,
V_2 -> V_5 , V_2 -> V_17 , & V_43 ,
V_46 ) ;
F_33 ( V_2 -> V_3 ) ;
if ( V_16 == 0 ) {
V_2 -> V_44 = V_43 ;
V_2 -> V_45 = 0 ;
}
F_2 ( V_2 -> V_3 , L_24 ,
V_16 , V_43 ) ;
return V_16 ;
}
static T_1 F_34 ( struct V_40 * V_40 ,
char T_2 * V_47 ,
T_3 V_48 ,
T_4 * V_49 )
{
struct V_1 * V_2 ;
T_1 V_50 = 0 ;
int V_51 ;
int V_16 = 0 ;
unsigned long V_52 ;
V_2 = V_40 -> V_41 ;
if ( V_2 == NULL || ! V_2 -> V_27 )
return - V_23 ;
F_2 ( V_2 -> V_3 , L_25 , V_48 ) ;
while ( V_48 > 0 ) {
V_16 = F_35 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_53;
F_23 ( & V_2 -> V_30 ) ;
V_16 = F_35 ( & V_2 -> V_29 ) ;
if ( V_16 )
goto V_53;
if ( V_2 -> V_44 == V_2 -> V_45 ) {
V_16 = F_28 ( V_2 ) ;
if ( V_16 ) {
F_23 ( & V_2 -> V_29 ) ;
goto V_53;
}
if ( V_2 -> V_45 == V_2 -> V_44 ) {
F_23 ( & V_2 -> V_29 ) ;
goto V_53;
}
}
V_51 = V_2 -> V_44 - V_2 -> V_45 ;
if ( V_51 > V_48 )
V_51 = V_48 ;
V_52 = F_36 ( V_47 , V_2 -> V_5 + V_2 -> V_45 , V_51 ) ;
if ( V_52 ) {
V_16 = - V_54 ;
V_2 -> V_45 += V_51 - V_52 ;
F_23 ( & V_2 -> V_29 ) ;
goto V_53;
}
V_48 -= V_51 ;
V_50 += V_51 ;
V_47 += V_51 ;
V_2 -> V_45 += V_51 ;
F_23 ( & V_2 -> V_29 ) ;
}
V_53:
if ( V_50 ) {
F_2 ( V_2 -> V_3 , L_26 , V_50 ) ;
return V_50 ;
}
F_2 ( V_2 -> V_3 , L_27 , V_16 ) ;
return V_16 ;
}
static int V_35 ( struct V_32 * V_55 , void * V_56 ,
T_3 V_57 , bool V_42 )
{
struct V_1 * V_2 = F_37 ( V_55 , struct V_1 , V_32 ) ;
int V_51 ;
F_2 ( V_2 -> V_3 , L_28 , V_57 , V_42 ) ;
if ( ! V_2 -> V_27 ) {
F_2 ( V_2 -> V_3 , L_22 ) ;
return 0 ;
}
F_22 ( & V_2 -> V_30 ) ;
F_22 ( & V_2 -> V_29 ) ;
F_23 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_44 == V_2 -> V_45 )
( void ) F_28 ( V_2 ) ;
V_51 = V_2 -> V_44 - V_2 -> V_45 ;
if ( V_51 > V_57 )
V_51 = V_57 ;
memcpy ( V_56 , V_2 -> V_5 + V_2 -> V_45 , V_51 ) ;
V_2 -> V_45 += V_51 ;
F_23 ( & V_2 -> V_29 ) ;
F_2 ( V_2 -> V_3 , L_29 , V_51 ) ;
return V_51 ;
}
static int F_38 ( struct V_6 * V_3 ,
T_5 V_58 )
{
F_2 ( V_3 , L_30 ) ;
return 0 ;
}
static int F_39 ( struct V_6 * V_3 )
{
F_2 ( V_3 , L_31 ) ;
return 0 ;
}
