static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 T_2 * V_3 )
{
return V_2 -> V_4 ? F_2 ( V_3 ) : F_3 ( V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 T_2 * V_3 )
{
V_2 -> V_4 ? F_5 ( V_5 , V_3 ) : F_6 ( V_5 , V_3 ) ;
}
static int F_7 ( struct V_6 * V_7 , bool V_8 )
{
struct V_9 * clock = F_8 ( V_7 ) ;
struct V_1 * V_2 = clock -> V_2 ;
T_1 V_10 = F_9 ( clock -> V_11 ) ;
unsigned long V_12 ;
unsigned int V_13 ;
T_1 V_14 ;
F_10 ( & V_2 -> V_15 , V_12 ) ;
V_14 = F_1 ( V_2 , V_2 -> V_16 ) ;
if ( V_8 )
V_14 &= ~ V_10 ;
else
V_14 |= V_10 ;
F_4 ( V_2 , V_14 , V_2 -> V_16 ) ;
if ( ! V_2 -> V_17 ) {
F_1 ( V_2 , V_2 -> V_16 ) ;
F_11 ( V_2 -> V_16 ) ;
}
F_12 ( & V_2 -> V_15 , V_12 ) ;
if ( ! V_8 || ! V_2 -> V_17 )
return 0 ;
for ( V_13 = 1000 ; V_13 > 0 ; -- V_13 ) {
if ( ! ( F_1 ( V_2 , V_2 -> V_17 ) & V_10 ) )
break;
F_13 () ;
}
if ( ! V_13 ) {
F_14 ( L_1 , V_18 ,
V_2 -> V_16 , clock -> V_11 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
return F_7 ( V_7 , true ) ;
}
static void F_16 ( struct V_6 * V_7 )
{
F_7 ( V_7 , false ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_9 * clock = F_8 ( V_7 ) ;
struct V_1 * V_2 = clock -> V_2 ;
T_1 V_14 ;
if ( V_2 -> V_17 )
V_14 = F_1 ( V_2 , V_2 -> V_17 ) ;
else
V_14 = F_1 ( V_2 , V_2 -> V_16 ) ;
return ! ( V_14 & F_9 ( clock -> V_11 ) ) ;
}
static struct V_20 * T_3 F_18 ( const char * V_21 ,
const char * V_22 , unsigned int V_23 ,
struct V_1 * V_2 )
{
struct V_24 V_25 ;
struct V_9 * clock ;
struct V_20 * V_20 ;
clock = F_19 ( sizeof( * clock ) , V_26 ) ;
if ( ! clock ) {
F_14 ( L_2 , V_18 ) ;
return F_20 ( - V_27 ) ;
}
V_25 . V_21 = V_21 ;
V_25 . V_28 = & V_29 ;
V_25 . V_12 = V_30 | V_31 ;
if ( ! strcmp ( V_21 , L_3 ) ) {
F_21 ( L_4 , V_21 ) ;
V_25 . V_12 |= V_32 ;
}
V_25 . V_33 = & V_22 ;
V_25 . V_34 = 1 ;
clock -> V_11 = V_23 ;
clock -> V_2 = V_2 ;
clock -> V_7 . V_25 = & V_25 ;
V_20 = F_22 ( NULL , & clock -> V_7 ) ;
if ( F_23 ( V_20 ) )
F_24 ( clock ) ;
return V_20 ;
}
static void T_3 F_25 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
const char * V_37 ;
struct V_20 * * V_38 ;
unsigned int V_13 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_26 ) ;
V_38 = F_26 ( V_39 , sizeof( * V_38 ) , V_26 ) ;
if ( V_2 == NULL || V_38 == NULL ) {
F_24 ( V_2 ) ;
F_24 ( V_38 ) ;
F_14 ( L_5 , V_18 ) ;
return;
}
F_27 ( & V_2 -> V_15 ) ;
V_2 -> V_40 . V_38 = V_38 ;
V_2 -> V_16 = F_28 ( V_36 , 0 ) ;
V_2 -> V_17 = F_28 ( V_36 , 1 ) ;
if ( V_2 -> V_16 == NULL ) {
F_14 ( L_6 , V_18 ) ;
F_24 ( V_2 ) ;
F_24 ( V_38 ) ;
return;
}
if ( F_29 ( V_36 , L_7 ) )
V_2 -> V_4 = true ;
for ( V_13 = 0 ; V_13 < V_39 ; ++ V_13 )
V_38 [ V_13 ] = F_20 ( - V_41 ) ;
if ( F_30 ( V_36 , L_8 , & V_13 ) )
V_37 = L_8 ;
else
V_37 = L_9 ;
for ( V_13 = 0 ; V_13 < V_39 ; ++ V_13 ) {
const char * V_22 ;
const char * V_21 ;
T_1 V_42 ;
int V_43 ;
V_43 = F_31 ( V_36 , L_10 ,
V_13 , & V_21 ) ;
if ( V_43 < 0 || strlen ( V_21 ) == 0 )
continue;
V_22 = F_32 ( V_36 , V_13 ) ;
V_43 = F_33 ( V_36 , V_37 , V_13 , & V_42 ) ;
if ( V_22 == NULL || V_43 < 0 )
break;
if ( V_42 >= V_39 ) {
F_14 ( L_11 ,
V_18 , V_36 -> V_21 , V_21 , V_42 ) ;
continue;
}
V_38 [ V_42 ] = F_18 ( V_21 , V_22 ,
V_42 , V_2 ) ;
if ( ! F_23 ( V_38 [ V_42 ] ) ) {
V_2 -> V_40 . V_44 = F_34 ( V_2 -> V_40 . V_44 ,
V_42 + 1 ) ;
F_35 ( V_38 [ V_42 ] , V_21 , NULL ) ;
} else {
F_14 ( L_12 ,
V_18 , V_36 -> V_21 , V_21 , F_36 ( V_38 [ V_42 ] ) ) ;
}
}
F_37 ( V_36 , V_45 , & V_2 -> V_40 ) ;
}
int F_38 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_35 * V_36 = V_49 -> V_50 ;
struct V_51 V_52 ;
struct V_20 * V_20 ;
int V_13 = 0 ;
int error ;
while ( ! F_39 ( V_36 , L_13 , L_14 , V_13 ,
& V_52 ) ) {
if ( F_29 ( V_52 . V_36 ,
L_15 ) )
goto V_53;
if ( ! strcmp ( V_52 . V_36 -> V_21 , L_16 ) )
goto V_53;
F_40 ( V_52 . V_36 ) ;
V_13 ++ ;
}
return 0 ;
V_53:
V_20 = F_41 ( & V_52 ) ;
F_40 ( V_52 . V_36 ) ;
if ( F_23 ( V_20 ) )
return F_36 ( V_20 ) ;
error = F_42 ( V_49 ) ;
if ( error ) {
F_43 ( V_49 , L_17 , error ) ;
goto V_54;
}
error = F_44 ( V_49 , V_20 ) ;
if ( error ) {
F_43 ( V_49 , L_18 , V_20 , error ) ;
goto V_55;
}
return 0 ;
V_55:
F_45 ( V_49 ) ;
V_54:
F_46 ( V_20 ) ;
return error ;
}
void F_47 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
if ( ! F_48 ( & V_49 -> V_56 . V_57 -> V_58 ) )
F_45 ( V_49 ) ;
}
void T_3 F_49 ( struct V_35 * V_36 )
{
struct V_46 * V_59 ;
T_1 V_60 ;
if ( F_50 ( V_36 , L_19 , & V_60 ) ) {
F_51 ( L_20 , V_36 -> V_61 ) ;
return;
}
V_59 = F_19 ( sizeof( * V_59 ) , V_26 ) ;
if ( ! V_59 )
return;
V_59 -> V_21 = V_36 -> V_21 ;
V_59 -> V_12 = V_62 ;
V_59 -> V_63 = F_38 ;
V_59 -> V_64 = F_47 ;
F_52 ( V_59 , & V_65 , false ) ;
F_53 ( V_36 , V_59 ) ;
}
