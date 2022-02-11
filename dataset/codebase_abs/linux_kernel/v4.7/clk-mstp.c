static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * clock = F_2 ( V_2 ) ;
struct V_5 * V_6 = clock -> V_6 ;
T_1 V_7 = F_3 ( clock -> V_8 ) ;
unsigned long V_9 ;
unsigned int V_10 ;
T_1 V_11 ;
F_4 ( & V_6 -> V_12 , V_9 ) ;
V_11 = F_5 ( V_6 -> V_13 ) ;
if ( V_3 )
V_11 &= ~ V_7 ;
else
V_11 |= V_7 ;
F_6 ( V_11 , V_6 -> V_13 ) ;
F_7 ( & V_6 -> V_12 , V_9 ) ;
if ( ! V_3 || ! V_6 -> V_14 )
return 0 ;
for ( V_10 = 1000 ; V_10 > 0 ; -- V_10 ) {
if ( ! ( F_5 ( V_6 -> V_14 ) & V_7 ) )
break;
F_8 () ;
}
if ( ! V_10 ) {
F_9 ( L_1 , V_15 ,
V_6 -> V_13 , clock -> V_8 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * clock = F_2 ( V_2 ) ;
struct V_5 * V_6 = clock -> V_6 ;
T_1 V_11 ;
if ( V_6 -> V_14 )
V_11 = F_5 ( V_6 -> V_14 ) ;
else
V_11 = F_5 ( V_6 -> V_13 ) ;
return ! ( V_11 & F_3 ( clock -> V_8 ) ) ;
}
static struct V_17 * T_2
F_13 ( const char * V_18 , const char * V_19 ,
unsigned int V_20 , struct V_5 * V_6 )
{
struct V_21 V_22 ;
struct V_4 * clock ;
struct V_17 * V_17 ;
clock = F_14 ( sizeof( * clock ) , V_23 ) ;
if ( ! clock ) {
F_9 ( L_2 , V_15 ) ;
return F_15 ( - V_24 ) ;
}
V_22 . V_18 = V_18 ;
V_22 . V_25 = & V_26 ;
V_22 . V_9 = V_27 | V_28 ;
V_22 . V_29 = & V_19 ;
V_22 . V_30 = 1 ;
clock -> V_8 = V_20 ;
clock -> V_6 = V_6 ;
clock -> V_2 . V_22 = & V_22 ;
V_17 = F_16 ( NULL , & clock -> V_2 ) ;
if ( F_17 ( V_17 ) )
F_18 ( clock ) ;
return V_17 ;
}
static void T_2 F_19 ( struct V_31 * V_32 )
{
struct V_5 * V_6 ;
const char * V_33 ;
struct V_17 * * V_34 ;
unsigned int V_10 ;
V_6 = F_14 ( sizeof( * V_6 ) , V_23 ) ;
V_34 = F_20 ( V_35 * sizeof( * V_34 ) , V_23 ) ;
if ( V_6 == NULL || V_34 == NULL ) {
F_18 ( V_6 ) ;
F_18 ( V_34 ) ;
F_9 ( L_3 , V_15 ) ;
return;
}
F_21 ( & V_6 -> V_12 ) ;
V_6 -> V_36 . V_34 = V_34 ;
V_6 -> V_13 = F_22 ( V_32 , 0 ) ;
V_6 -> V_14 = F_22 ( V_32 , 1 ) ;
if ( V_6 -> V_13 == NULL ) {
F_9 ( L_4 , V_15 ) ;
F_18 ( V_6 ) ;
F_18 ( V_34 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_35 ; ++ V_10 )
V_34 [ V_10 ] = F_15 ( - V_37 ) ;
if ( F_23 ( V_32 , L_5 , & V_10 ) )
V_33 = L_5 ;
else
V_33 = L_6 ;
for ( V_10 = 0 ; V_10 < V_35 ; ++ V_10 ) {
const char * V_19 ;
const char * V_18 ;
T_1 V_38 ;
int V_39 ;
V_39 = F_24 ( V_32 , L_7 ,
V_10 , & V_18 ) ;
if ( V_39 < 0 || strlen ( V_18 ) == 0 )
continue;
V_19 = F_25 ( V_32 , V_10 ) ;
V_39 = F_26 ( V_32 , V_33 , V_10 , & V_38 ) ;
if ( V_19 == NULL || V_39 < 0 )
break;
if ( V_38 >= V_35 ) {
F_9 ( L_8 ,
V_15 , V_32 -> V_18 , V_18 , V_38 ) ;
continue;
}
V_34 [ V_38 ] = F_13 ( V_18 , V_19 ,
V_38 , V_6 ) ;
if ( ! F_17 ( V_34 [ V_38 ] ) ) {
V_6 -> V_36 . V_40 = F_27 ( V_6 -> V_36 . V_40 ,
V_38 + 1 ) ;
F_28 ( V_34 [ V_38 ] , V_18 , NULL ) ;
} else {
F_9 ( L_9 ,
V_15 , V_32 -> V_18 , V_18 , F_29 ( V_34 [ V_38 ] ) ) ;
}
}
F_30 ( V_32 , V_41 , & V_6 -> V_36 ) ;
}
int F_31 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_31 * V_32 = V_45 -> V_46 ;
struct V_47 V_48 ;
struct V_17 * V_17 ;
int V_10 = 0 ;
int error ;
while ( ! F_32 ( V_32 , L_10 , L_11 , V_10 ,
& V_48 ) ) {
if ( F_33 ( V_48 . V_32 ,
L_12 ) )
goto V_49;
if ( ! strcmp ( V_48 . V_32 -> V_18 , L_13 ) )
goto V_49;
F_34 ( V_48 . V_32 ) ;
V_10 ++ ;
}
return 0 ;
V_49:
V_17 = F_35 ( & V_48 ) ;
F_34 ( V_48 . V_32 ) ;
if ( F_17 ( V_17 ) )
return F_29 ( V_17 ) ;
error = F_36 ( V_45 ) ;
if ( error ) {
F_37 ( V_45 , L_14 , error ) ;
goto V_50;
}
error = F_38 ( V_45 , V_17 ) ;
if ( error ) {
F_37 ( V_45 , L_15 , V_17 , error ) ;
goto V_51;
}
return 0 ;
V_51:
F_39 ( V_45 ) ;
V_50:
F_40 ( V_17 ) ;
return error ;
}
void F_41 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
if ( ! F_42 ( & V_45 -> V_52 . V_53 -> V_54 ) )
F_39 ( V_45 ) ;
}
void T_2 F_43 ( struct V_31 * V_32 )
{
struct V_42 * V_55 ;
T_1 V_56 ;
if ( F_44 ( V_32 , L_16 , & V_56 ) ) {
F_45 ( L_17 , V_32 -> V_57 ) ;
return;
}
V_55 = F_14 ( sizeof( * V_55 ) , V_23 ) ;
if ( ! V_55 )
return;
V_55 -> V_18 = V_32 -> V_18 ;
V_55 -> V_9 = V_58 ;
V_55 -> V_59 = F_31 ;
V_55 -> V_60 = F_41 ;
F_46 ( V_55 , & V_61 , false ) ;
F_47 ( V_32 , V_55 ) ;
}
