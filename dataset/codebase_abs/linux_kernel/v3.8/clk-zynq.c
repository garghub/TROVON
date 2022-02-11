static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_3 * F_3 ( F_4 ( V_5 -> V_6 ) ) ;
}
static void T_1 F_5 ( struct V_7 * V_8 )
{
struct V_9 V_10 ;
struct V_4 * V_5 ;
const char * V_11 ;
struct V_12 * V_12 ;
T_2 V_13 [ 2 ] ;
int V_14 ;
V_14 = F_6 ( V_8 , L_1 , V_13 , F_7 ( V_13 ) ) ;
if ( F_8 ( V_14 ) )
return;
V_5 = F_9 ( sizeof( * V_5 ) , V_15 ) ;
if ( F_8 ( ! V_5 ) )
return;
V_5 -> V_6 = V_16 + V_13 [ 0 ] ;
V_5 -> V_17 = V_16 + V_13 [ 1 ] ;
F_10 ( V_8 , L_2 , & V_10 . V_18 ) ;
V_10 . V_19 = & V_20 ;
V_11 = F_11 ( V_8 , 0 ) ;
V_10 . V_21 = & V_11 ;
V_10 . V_22 = 1 ;
V_5 -> V_2 . V_10 = & V_10 ;
V_12 = F_12 ( NULL , & V_5 -> V_2 ) ;
if ( F_8 ( F_13 ( V_12 ) ) )
return;
V_14 = F_14 ( V_8 , V_23 , V_12 ) ;
if ( F_8 ( V_14 ) )
return;
}
static unsigned long F_15 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_24 * V_25 = F_16 ( V_2 ) ;
return V_3 / F_17 ( F_4 ( V_25 -> V_26 ) ) ;
}
static T_3 F_18 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_16 ( V_2 ) ;
return F_19 ( F_4 ( V_25 -> V_26 ) ) ;
}
static void T_1 F_20 ( struct V_7 * V_8 )
{
struct V_24 * V_25 ;
const char * V_21 [ 3 ] ;
struct V_9 V_10 ;
int V_27 = 0 , V_28 ;
const char * V_18 ;
struct V_12 * V_12 ;
T_2 V_29 ;
int V_30 ;
V_28 = F_21 ( V_8 , L_1 , & V_29 ) ;
if ( F_8 ( V_28 ) )
return;
V_25 = F_9 ( sizeof( * V_25 ) , V_15 ) ;
if ( F_8 ( ! V_25 ) )
return;
V_25 -> V_26 = V_16 + V_29 ;
F_22 ( & V_25 -> V_31 ) ;
V_10 . V_18 = V_8 -> V_18 ;
V_10 . V_19 = & V_32 ;
for ( V_30 = 0 ; V_30 < F_7 ( V_21 ) ; V_30 ++ )
V_21 [ V_30 ] = F_11 ( V_8 , V_30 ) ;
V_10 . V_21 = V_21 ;
V_10 . V_22 = F_7 ( V_21 ) ;
V_25 -> V_2 . V_10 = & V_10 ;
V_12 = F_12 ( NULL , & V_25 -> V_2 ) ;
if ( F_8 ( F_13 ( V_12 ) ) )
return;
V_28 = F_14 ( V_8 , V_23 , V_12 ) ;
if ( F_8 ( V_28 ) )
return;
V_28 = F_23 ( V_8 , L_2 , 0 ,
& V_18 ) ;
if ( F_8 ( V_28 ) )
return;
V_25 -> V_33 [ 0 ] = F_24 ( NULL , V_18 , V_8 -> V_18 , 0 ,
V_25 -> V_26 , 0 , 0 ,
& V_25 -> V_31 ) ;
if ( F_8 ( F_13 ( V_25 -> V_33 [ 0 ] ) ) )
return;
V_27 ++ ;
V_28 = F_23 ( V_8 , L_2 , 1 ,
& V_18 ) ;
if ( V_28 != - V_34 ) {
V_25 -> V_33 [ 1 ] = F_24 ( NULL , V_18 , V_8 -> V_18 , 0 ,
V_25 -> V_26 , 1 , 0 ,
& V_25 -> V_31 ) ;
if ( F_8 ( F_13 ( V_25 -> V_33 [ 1 ] ) ) )
return;
V_27 ++ ;
}
V_25 -> V_35 . V_36 = V_25 -> V_33 ;
V_25 -> V_35 . V_27 = V_27 ;
V_28 = F_14 ( V_8 , V_37 ,
& V_25 -> V_35 ) ;
if ( F_8 ( V_28 ) )
return;
}
static T_3 F_25 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_26 ( V_2 ) ;
return F_27 ( F_4 ( V_39 -> V_26 ) ) ;
}
static unsigned long F_28 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_38 * V_39 = F_26 ( V_2 ) ;
return V_3 / F_29 ( F_4 ( V_39 -> V_26 ) ) ;
}
static unsigned long F_30 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_40 ( V_41 ) ;
struct V_42 * V_43 ;
bool V_44 ;
V_43 = F_31 (hw)
V_44 = F_32 ( F_4 ( V_43 -> V_45 ) ) ;
switch ( V_43 -> V_46 ) {
case V_47 :
V_41 = V_3 ;
break;
case V_48 :
V_41 = V_3 / 2 ;
break;
case V_49 :
V_41 = V_3 / ( V_44 ? 3 : 2 ) ;
break;
case V_50 :
V_41 = V_3 / ( V_44 ? 6 : 4 ) ;
break;
} ;
return V_41 ;
}
static struct V_12 * F_33 ( struct V_7 * V_8 , T_3 V_46 ,
void T_4 * V_45 )
{
struct V_42 * V_43 ;
struct V_9 V_10 ;
struct V_12 * V_12 ;
int V_28 ;
V_28 = F_23 ( V_8 , L_2 ,
V_46 , & V_10 . V_18 ) ;
if ( F_8 ( V_28 ) )
goto V_51;
V_43 = F_9 ( sizeof( * V_43 ) , V_15 ) ;
if ( ! V_43 )
goto V_52;
V_43 -> V_45 = V_45 ;
V_43 -> V_46 = V_46 ;
V_10 . V_19 = & V_53 ;
V_10 . V_21 = & V_8 -> V_18 ;
V_10 . V_22 = 1 ;
V_43 -> V_2 . V_10 = & V_10 ;
V_12 = F_12 ( NULL , & V_43 -> V_2 ) ;
if ( F_8 ( F_13 ( V_12 ) ) )
goto V_54;
return V_12 ;
V_54:
F_34 ( V_43 ) ;
V_52:
V_51:
return F_35 ( - V_55 ) ;
}
static void T_1 F_36 ( struct V_7 * V_8 )
{
struct V_38 * V_39 ;
const char * V_21 [ 3 ] ;
struct V_9 V_10 ;
void T_4 * V_45 ;
struct V_12 * V_12 ;
T_2 V_29 [ 2 ] ;
int V_28 ;
int V_30 ;
V_28 = F_6 ( V_8 , L_1 , V_29 , F_7 ( V_29 ) ) ;
if ( F_8 ( V_28 ) )
return;
V_39 = F_9 ( sizeof( * V_39 ) , V_15 ) ;
if ( F_8 ( ! V_39 ) )
return;
V_39 -> V_26 = V_16 + V_29 [ 0 ] ;
V_45 = V_16 + V_29 [ 1 ] ;
F_22 ( & V_39 -> V_31 ) ;
V_10 . V_18 = V_8 -> V_18 ;
V_10 . V_19 = & V_56 ;
for ( V_30 = 0 ; V_30 < F_7 ( V_21 ) ; V_30 ++ )
V_21 [ V_30 ] = F_11 ( V_8 , V_30 ) ;
V_10 . V_21 = V_21 ;
V_10 . V_22 = F_7 ( V_21 ) ;
V_39 -> V_2 . V_10 = & V_10 ;
V_12 = F_12 ( NULL , & V_39 -> V_2 ) ;
if ( F_8 ( F_13 ( V_12 ) ) )
return;
V_28 = F_14 ( V_8 , V_23 , V_12 ) ;
if ( F_8 ( V_28 ) )
return;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
V_39 -> V_57 [ V_30 ] = F_33 ( V_8 , V_30 , V_45 ) ;
if ( F_8 ( F_13 ( V_39 -> V_57 [ V_30 ] ) ) )
return;
}
V_39 -> V_35 . V_36 = V_39 -> V_57 ;
V_39 -> V_35 . V_27 = V_30 ;
V_28 = F_14 ( V_8 , V_37 ,
& V_39 -> V_35 ) ;
if ( F_8 ( V_28 ) )
return;
}
void T_1 F_37 ( void T_4 * V_58 )
{
V_16 = V_58 ;
F_38 ( V_59 ) ;
}
