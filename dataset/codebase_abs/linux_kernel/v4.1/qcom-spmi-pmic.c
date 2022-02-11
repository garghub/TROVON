static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 , V_6 , V_7 , type , V_8 ;
const char * V_9 = L_1 ;
int V_10 , V_11 ;
V_10 = F_2 ( V_2 , V_12 , & type ) ;
if ( V_10 < 0 )
return;
if ( type != V_13 )
return;
V_10 = F_2 ( V_2 , V_14 , & V_8 ) ;
if ( V_10 < 0 )
return;
for ( V_11 = 0 ; V_11 < F_3 ( V_15 ) ; V_11 ++ ) {
if ( V_8 == ( unsigned long ) V_15 [ V_11 ] . V_16 )
break;
}
if ( V_11 != F_3 ( V_15 ) )
V_9 = V_15 [ V_11 ] . V_17 ;
V_10 = F_2 ( V_2 , V_18 , & V_5 ) ;
if ( V_10 < 0 )
return;
V_10 = F_2 ( V_2 , V_19 , & V_6 ) ;
if ( V_10 < 0 )
return;
V_10 = F_2 ( V_2 , V_20 , & V_7 ) ;
if ( V_10 < 0 )
return;
if ( ( V_8 == V_21 || V_8 == V_22 ) &&
V_7 < 0x02 )
V_7 ++ ;
if ( V_8 == V_23 )
V_6 = V_5 ;
F_4 ( V_4 , L_2 , V_8 , V_9 , V_7 , V_6 ) ;
}
static int F_5 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_4 . V_28 ;
struct V_1 * V_1 ;
V_1 = F_6 ( V_25 , & V_29 ) ;
if ( F_7 ( V_1 ) )
return F_8 ( V_1 ) ;
F_1 ( V_1 , & V_25 -> V_4 ) ;
return F_9 ( V_27 , NULL , NULL , & V_25 -> V_4 ) ;
}
static void F_10 ( struct V_24 * V_25 )
{
F_11 ( & V_25 -> V_4 ) ;
}
