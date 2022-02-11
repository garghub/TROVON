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
F_11 ( & V_2 -> V_15 , V_12 ) ;
if ( ! V_8 || ! V_2 -> V_17 )
return 0 ;
for ( V_13 = 1000 ; V_13 > 0 ; -- V_13 ) {
if ( ! ( F_1 ( V_2 , V_2 -> V_17 ) & V_10 ) )
break;
F_12 () ;
}
if ( ! V_13 ) {
F_13 ( L_1 , V_18 ,
V_2 -> V_16 , clock -> V_11 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
return F_7 ( V_7 , true ) ;
}
static void F_15 ( struct V_6 * V_7 )
{
F_7 ( V_7 , false ) ;
}
static int F_16 ( struct V_6 * V_7 )
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
static struct V_20 * T_3
F_17 ( const char * V_21 , const char * V_22 ,
unsigned int V_23 , struct V_1 * V_2 )
{
struct V_24 V_25 ;
struct V_9 * clock ;
struct V_20 * V_20 ;
clock = F_18 ( sizeof( * clock ) , V_26 ) ;
if ( ! clock ) {
F_13 ( L_2 , V_18 ) ;
return F_19 ( - V_27 ) ;
}
V_25 . V_21 = V_21 ;
V_25 . V_28 = & V_29 ;
V_25 . V_12 = V_30 | V_31 ;
V_25 . V_32 = & V_22 ;
V_25 . V_33 = 1 ;
clock -> V_11 = V_23 ;
clock -> V_2 = V_2 ;
clock -> V_7 . V_25 = & V_25 ;
V_20 = F_20 ( NULL , & clock -> V_7 ) ;
if ( F_21 ( V_20 ) )
F_22 ( clock ) ;
return V_20 ;
}
static void T_3 F_23 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
const char * V_36 ;
struct V_20 * * V_37 ;
unsigned int V_13 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_26 ) ;
V_37 = F_24 ( V_38 , sizeof( * V_37 ) , V_26 ) ;
if ( V_2 == NULL || V_37 == NULL ) {
F_22 ( V_2 ) ;
F_22 ( V_37 ) ;
F_13 ( L_3 , V_18 ) ;
return;
}
F_25 ( & V_2 -> V_15 ) ;
V_2 -> V_39 . V_37 = V_37 ;
V_2 -> V_16 = F_26 ( V_35 , 0 ) ;
V_2 -> V_17 = F_26 ( V_35 , 1 ) ;
if ( V_2 -> V_16 == NULL ) {
F_13 ( L_4 , V_18 ) ;
F_22 ( V_2 ) ;
F_22 ( V_37 ) ;
return;
}
if ( F_27 ( V_35 , L_5 ) )
V_2 -> V_4 = true ;
for ( V_13 = 0 ; V_13 < V_38 ; ++ V_13 )
V_37 [ V_13 ] = F_19 ( - V_40 ) ;
if ( F_28 ( V_35 , L_6 , & V_13 ) )
V_36 = L_6 ;
else
V_36 = L_7 ;
for ( V_13 = 0 ; V_13 < V_38 ; ++ V_13 ) {
const char * V_22 ;
const char * V_21 ;
T_1 V_41 ;
int V_42 ;
V_42 = F_29 ( V_35 , L_8 ,
V_13 , & V_21 ) ;
if ( V_42 < 0 || strlen ( V_21 ) == 0 )
continue;
V_22 = F_30 ( V_35 , V_13 ) ;
V_42 = F_31 ( V_35 , V_36 , V_13 , & V_41 ) ;
if ( V_22 == NULL || V_42 < 0 )
break;
if ( V_41 >= V_38 ) {
F_13 ( L_9 ,
V_18 , V_35 -> V_21 , V_21 , V_41 ) ;
continue;
}
V_37 [ V_41 ] = F_17 ( V_21 , V_22 ,
V_41 , V_2 ) ;
if ( ! F_21 ( V_37 [ V_41 ] ) ) {
V_2 -> V_39 . V_43 = F_32 ( V_2 -> V_39 . V_43 ,
V_41 + 1 ) ;
F_33 ( V_37 [ V_41 ] , V_21 , NULL ) ;
} else {
F_13 ( L_10 ,
V_18 , V_35 -> V_21 , V_21 , F_34 ( V_37 [ V_41 ] ) ) ;
}
}
F_35 ( V_35 , V_44 , & V_2 -> V_39 ) ;
}
int F_36 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_34 * V_35 = V_48 -> V_49 ;
struct V_50 V_51 ;
struct V_20 * V_20 ;
int V_13 = 0 ;
int error ;
while ( ! F_37 ( V_35 , L_11 , L_12 , V_13 ,
& V_51 ) ) {
if ( F_27 ( V_51 . V_35 ,
L_13 ) )
goto V_52;
if ( ! strcmp ( V_51 . V_35 -> V_21 , L_14 ) )
goto V_52;
F_38 ( V_51 . V_35 ) ;
V_13 ++ ;
}
return 0 ;
V_52:
V_20 = F_39 ( & V_51 ) ;
F_38 ( V_51 . V_35 ) ;
if ( F_21 ( V_20 ) )
return F_34 ( V_20 ) ;
error = F_40 ( V_48 ) ;
if ( error ) {
F_41 ( V_48 , L_15 , error ) ;
goto V_53;
}
error = F_42 ( V_48 , V_20 ) ;
if ( error ) {
F_41 ( V_48 , L_16 , V_20 , error ) ;
goto V_54;
}
return 0 ;
V_54:
F_43 ( V_48 ) ;
V_53:
F_44 ( V_20 ) ;
return error ;
}
void F_45 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
if ( ! F_46 ( & V_48 -> V_55 . V_56 -> V_57 ) )
F_43 ( V_48 ) ;
}
void T_3 F_47 ( struct V_34 * V_35 )
{
struct V_45 * V_58 ;
T_1 V_59 ;
if ( F_48 ( V_35 , L_17 , & V_59 ) ) {
F_49 ( L_18 , V_35 -> V_60 ) ;
return;
}
V_58 = F_18 ( sizeof( * V_58 ) , V_26 ) ;
if ( ! V_58 )
return;
V_58 -> V_21 = V_35 -> V_21 ;
V_58 -> V_12 = V_61 ;
V_58 -> V_62 = F_36 ;
V_58 -> V_63 = F_45 ;
F_50 ( V_58 , & V_64 , false ) ;
F_51 ( V_35 , V_58 ) ;
}
