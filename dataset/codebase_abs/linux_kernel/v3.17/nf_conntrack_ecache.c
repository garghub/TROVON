static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 [ 16 ] ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 = 0 ;
enum V_1 V_11 = V_12 ;
F_2 ( & V_3 -> V_13 ) ;
F_3 (h, n, &pcpu->dying, hnnode) {
struct V_4 * V_14 = F_4 ( V_7 ) ;
if ( F_5 ( V_14 ) )
continue;
if ( F_6 ( V_15 , V_14 ) ) {
V_11 = V_16 ;
break;
}
F_7 ( V_17 , & V_14 -> V_18 ) ;
V_5 [ V_10 ] = V_14 ;
if ( ++ V_10 >= F_8 ( V_5 ) ) {
V_11 = V_19 ;
break;
}
}
F_9 ( & V_3 -> V_13 ) ;
while ( V_10 )
F_10 ( V_5 [ -- V_10 ] ) ;
return V_11 ;
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_12 ( V_21 , struct V_22 , V_24 . V_21 ) ;
int V_25 , V_26 = - 1 ;
struct V_2 * V_3 ;
F_13 () ;
F_14 (cpu) {
enum V_1 V_11 ;
V_3 = F_15 ( V_23 -> V_27 , V_25 ) ;
V_11 = F_1 ( V_3 ) ;
switch ( V_11 ) {
case V_16 :
V_26 = V_28 ;
goto V_29;
case V_19 :
V_26 = 0 ;
break;
case V_12 :
break;
}
}
V_29:
F_16 () ;
V_23 -> V_30 = V_26 > 0 ;
if ( V_26 >= 0 )
F_17 ( & V_23 -> V_24 , V_26 ) ;
}
void F_18 ( struct V_4 * V_14 )
{
struct V_31 * V_31 = F_19 ( V_14 ) ;
unsigned long V_32 , V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
int V_11 ;
F_20 () ;
V_35 = F_21 ( V_31 -> V_14 . V_40 ) ;
if ( V_35 == NULL )
goto V_41;
V_37 = F_22 ( V_14 ) ;
if ( V_37 == NULL )
goto V_41;
V_32 = F_23 ( & V_37 -> V_42 , 0 ) ;
if ( ! F_24 ( V_14 ) || F_5 ( V_14 ) || ! V_32 )
goto V_41;
V_33 = V_37 -> V_33 ;
if ( ! ( ( V_32 | V_33 ) & V_37 -> V_43 ) )
goto V_41;
V_39 . V_14 = V_14 ;
V_39 . V_44 = 0 ;
V_39 . V_45 = 0 ;
V_11 = V_35 -> V_46 ( V_32 | V_33 , & V_39 ) ;
if ( F_25 ( V_11 >= 0 && ! V_33 ) )
goto V_41;
F_26 ( & V_14 -> V_13 ) ;
if ( V_11 < 0 )
V_37 -> V_33 |= V_32 ;
else
V_37 -> V_33 &= ~ V_33 ;
F_27 ( & V_14 -> V_13 ) ;
V_41:
F_28 () ;
}
int F_29 ( struct V_31 * V_31 ,
struct V_34 * V_47 )
{
int V_11 ;
struct V_34 * V_35 ;
F_30 ( & V_48 ) ;
V_35 = F_31 ( V_31 -> V_14 . V_40 ,
F_32 ( & V_48 ) ) ;
if ( V_35 != NULL ) {
V_11 = - V_49 ;
goto V_41;
}
F_33 ( V_31 -> V_14 . V_40 , V_47 ) ;
V_11 = 0 ;
V_41:
F_34 ( & V_48 ) ;
return V_11 ;
}
void F_35 ( struct V_31 * V_31 ,
struct V_34 * V_47 )
{
struct V_34 * V_35 ;
F_30 ( & V_48 ) ;
V_35 = F_31 ( V_31 -> V_14 . V_40 ,
F_32 ( & V_48 ) ) ;
F_36 ( V_35 != V_47 ) ;
F_37 ( V_31 -> V_14 . V_40 , NULL ) ;
F_34 ( & V_48 ) ;
}
int F_38 ( struct V_31 * V_31 ,
struct V_50 * V_47 )
{
int V_11 ;
struct V_50 * V_35 ;
F_30 ( & V_48 ) ;
V_35 = F_31 ( V_31 -> V_14 . V_51 ,
F_32 ( & V_48 ) ) ;
if ( V_35 != NULL ) {
V_11 = - V_49 ;
goto V_41;
}
F_33 ( V_31 -> V_14 . V_51 , V_47 ) ;
V_11 = 0 ;
V_41:
F_34 ( & V_48 ) ;
return V_11 ;
}
void F_39 ( struct V_31 * V_31 ,
struct V_50 * V_47 )
{
struct V_50 * V_35 ;
F_30 ( & V_48 ) ;
V_35 = F_31 ( V_31 -> V_14 . V_51 ,
F_32 ( & V_48 ) ) ;
F_36 ( V_35 != V_47 ) ;
F_37 ( V_31 -> V_14 . V_51 , NULL ) ;
F_34 ( & V_48 ) ;
}
static int F_40 ( struct V_31 * V_31 )
{
struct V_52 * V_53 ;
V_53 = F_41 ( V_54 , sizeof( V_54 ) ,
V_55 ) ;
if ( ! V_53 )
goto V_29;
V_53 [ 0 ] . V_56 = & V_31 -> V_14 . V_57 ;
if ( V_31 -> V_58 != & V_59 )
V_53 [ 0 ] . V_60 = NULL ;
V_31 -> V_14 . V_61 =
F_42 ( V_31 , L_1 , V_53 ) ;
if ( ! V_31 -> V_14 . V_61 ) {
F_43 ( V_62 L_2 ) ;
goto V_63;
}
return 0 ;
V_63:
F_44 ( V_53 ) ;
V_29:
return - V_64 ;
}
static void F_45 ( struct V_31 * V_31 )
{
struct V_52 * V_53 ;
V_53 = V_31 -> V_14 . V_61 -> V_65 ;
F_46 ( V_31 -> V_14 . V_61 ) ;
F_44 ( V_53 ) ;
}
static int F_40 ( struct V_31 * V_31 )
{
return 0 ;
}
static void F_45 ( struct V_31 * V_31 )
{
}
int F_47 ( struct V_31 * V_31 )
{
V_31 -> V_14 . V_57 = V_66 ;
F_48 ( & V_31 -> V_14 . V_24 , F_11 ) ;
return F_40 ( V_31 ) ;
}
void F_49 ( struct V_31 * V_31 )
{
F_50 ( & V_31 -> V_14 . V_24 ) ;
F_45 ( V_31 ) ;
}
int F_51 ( void )
{
int V_11 = F_52 ( & V_67 ) ;
if ( V_11 < 0 )
F_53 ( L_3 ) ;
return V_11 ;
}
void F_54 ( void )
{
F_55 ( & V_67 ) ;
}
